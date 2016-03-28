#include "game.h"
#include "enemybase.h"

#include <QDebug>
#include <QtMath>

Game::Game(QObject *parent) : QObject(parent)
{
    scene = new QGraphicsScene();

    bg1 = new Background();
    bg2 = new Background();

    bg1->setPos(0, 0);
    bg2->setPos(0, -bg2->GetHeight());

    scene->addItem(bg1);
    scene->addItem(bg2);

    gameState = new GameState(scene);

    player = new Player(scene, gameState->getLives());

    scene->addItem(player);

    view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    view->show();
    view->setSceneRect(0.0, 0.0, 800, 600);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos((view->width()/2) - (player->boundingRect().width()/2),
                   (view->height()) - (player->boundingRect().height()));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));

    float desiredTimeForFrameMS = ((1.0f/60.0f) * 1000.0f);
    timer->start(desiredTimeForFrameMS);
}

GameState *Game::getState()
{
    return gameState;
}

Player *Game::getPlayer()
{
    return player;
}

void Game::Update()
{
    if(gameState->getLives()->getLives() > 0)
    {
        gameState->spawnEnemies();

        bg1->Update(gameState->getDeltaTime());
        bg2->Update(gameState->getDeltaTime());

        player->Update(gameState->getDeltaTime());
    }
    else
    {
        gameState->getMessage()->setText("You Died!");
    }
}
