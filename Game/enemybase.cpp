#include "enemybase.h"
#include <QDebug>
#include "laser.h"
#include "game.h"

extern Game* game;

EnemyBase::EnemyBase(QString filename, int maxLives)
    : MAX_LIVES(maxLives)
{
    this->lives = MAX_LIVES;
    speed = 1.0f;

    setPixmap(QPixmap(filename));
    setPos(-100, -100);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));

    float desiredTimeForFrameMS = ((1.0f/60.0f) * 1000.0f);
    timer->start(desiredTimeForFrameMS);

    scoreValue = (rand() % 5) + 45;

    kill();
}

bool EnemyBase::getIsAlive()
{
    return isAlive;
}

void EnemyBase::setIsAlive(bool alive)
{
    isAlive = alive;
}

void EnemyBase::kill()
{
    setIsAlive(false);
    setPos(-100, -100);
    lives = MAX_LIVES;
}

float EnemyBase::getSpeed()
{
    return speed;
}

void EnemyBase::CheckCollision()
{
    //COLLISION AGAINST LASER
    for(int i = 0; i < this->collidingItems().size(); ++i)
    {
        //get the collided item and cast it to a laser
        laser* obj = dynamic_cast<laser*>(this->collidingItems()[i]);

        if(obj) //if this is true
        {
            obj->setIsAlive(false); //kill laser

            lives--;    //Reduce lives

            if(lives == 0)
            {
                //Increase the score
                game->getState()->getScore()->increaseScore(scoreValue);

                //other wise kill the enemy
                kill();
            }

            return; //Done!
        }
    }
}

void EnemyBase::Move()
{
    //DOWN CHECK
    if(y() >= 600)
    {
        //other wise kill the enemy
        kill();
    }

    setPos(x(), y() + speed);    //Move down
}

void EnemyBase::Update()
{
    if(isAlive)
    {
        Move();
        CheckCollision();
    }
}
