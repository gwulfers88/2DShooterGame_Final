#include "laser.h"

laser::laser(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/sprites/Sprites/player_laser.png"));
    vY = 1;
    speed = 2.0f;
    setPos(-100, -100);

    deltaTime = new QTimer();
    connect(deltaTime, SIGNAL(timeout()), this, SLOT(Update()));

    float desiredTimeForFrameMS = ((1.0f/60.0f) * 1000.0f);
    deltaTime->start(desiredTimeForFrameMS);

    isAlive = false;
    //setActive(isAlive);
}

bool laser::getIsAlive()
{
    return isAlive;
}

void laser::setIsAlive(bool alive)
{
    isAlive = alive;
}

void laser::Update()
{
    if(isAlive)
    {
        //float t = 1/((1.0f/60.0f) * 1000.0f);
        vY *= speed;

        //TOP CHECK
        if(y() <= 0)
        {
            setIsAlive(false);
        }

        setPos(x(), y() - 10);
    }
    else
    {
        //Get them off the screen
        setPos(-100, -100);
    }
}
