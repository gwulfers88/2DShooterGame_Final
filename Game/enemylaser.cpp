#include "enemylaser.h"

EnemyLaser::EnemyLaser(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/sprites/Sprites/enemy_laser.png"));
    vY = 1;
    speed = 2.0f;
    setPos(-100, -100);

    deltaTime = new QTimer();
    connect(deltaTime, SIGNAL(timeout()), this, SLOT(Update()));

    float desiredTimeForFrameMS = ((1.0f/60.0f) * 1000.0f);
    deltaTime->start(desiredTimeForFrameMS);

    isAlive = false;
}

bool EnemyLaser::getIsAlive()
{
    return isAlive;
}

void EnemyLaser::setIsAlive(bool alive)
{
    isAlive = alive;
}

void EnemyLaser::Update()
{
    if(isAlive)
    {
        //float t = 1/((1.0f/60.0f) * 1000.0f);
        vY *= speed;

        //TOP CHECK
        if(y() >= 800)
        {
            setIsAlive(false);
        }

        setPos(x(), y() + 10);
    }
    else
    {
        //Get them off the screen
        setPos(-100, -100);
    }
}
