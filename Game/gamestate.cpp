#include "gamestate.h"
#include "enemyboss.h"

#include <QKeyEvent>

EnemyBoss *boss = 0;
bool bossEncountered = false;
bool gameStart = true;

GameState::GameState(QGraphicsScene *scene, QObject * parent)
    : QObject(parent)
{
    this->scene = scene;

    meteorPool = new MeteorPool(5, scene, ":/sprites/Sprites/meteor_large1.png");
    scannerPool = new ScannerPool(5, scene, ":/sprites/Sprites/enemy_scanner.png");
    actionMusic = new SoundManager("SFX/action_music.wav");

    score = new ScoreManager();
    scene->addItem(score);

    lives = new LivesManager();
    scene->addItem(lives);

    message = new MessageManager();
    scene->addItem(message);

    message->setText("");

    boss = new EnemyBoss(":/sprites/Sprites/enemy_boss.png", 100, scene);
    boss->setPos(-100, -100);
    boss->setScanners(scannerPool);
    boss->setIsAlive(false);
    scene->addItem(boss);

    t = 1/((1.0f/60.0f) * 1000.0f);

    meteorSpawnTimer = 0;
    meteorSpawnRate = 10.0f;

    scannerSpawnTimer = 0;
    scannerSpawnRate = 20.0f;

    actionMusic->Play();
}

int maxScore = 1000;
float percent = 0.2f;

void GameState::spawnEnemies()
{
    if(gameStart)
    {
        //determine at what score ammount we will add lives to the player
        int lifeAdd = maxScore * percent;

        //Check if we have reached the score amount to add lives to the player
        if(score->getScore() >= lifeAdd)
        {
            //Increase the lives by one
            lives->increaseLives(1);
            percent += 0.2f; //increase our percentage value
        }

        //SPAWN GRUNTS ONLY IF WE HAVE LESS THAN 1000 pts.
        if(score->getScore() < 500)
        {
            //METEOR SPAWNER
            meteorSpawnTimer += t;

            if(meteorSpawnTimer >= meteorSpawnRate)
            {
                meteorPool->SpawnObject(rand() % 700, 0);
                meteorSpawnTimer = 0;
            }

            //SPAWN SCANNER ONLY AFTER WE HAVE 200 pts.
            if(score->getScore() > 200)
            {
                //SCANNER SPAWNER
                scannerSpawnTimer += t;

                if(scannerSpawnTimer >= scannerSpawnRate)
                {
                    scannerPool->SpawnObject(rand() % 700, 0);
                    scannerSpawnTimer = 0;
                }
            }
        }
        else
        {
            //TODO: BOOS FIGHT!!!
            if(boss && !bossEncountered)
            {
                boss->setPos(400, 0);
                boss->setIsAlive(true);

                bossEncountered = true;
            }
            else
            {
                if(!boss->getIsAlive())
                {
                    if(scannerPool->getLiveCount() > 0)
                    {
                        scannerPool->destroyAll();
                    }

                    message->setText("You Win!");
                }
            }
        }
    }
}

float GameState::getDeltaTime()
{
    return t;
}

ScoreManager *GameState::getScore()
{
    return score;
}

LivesManager *GameState::getLives()
{
    return lives;
}

MessageManager *GameState::getMessage()
{
    return message;
}

