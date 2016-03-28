#include "livesmanager.h"

LivesManager::LivesManager()
    : MAX_LIVES(5)
{
    lives = MAX_LIVES;
    setPlainText(QString("Lives: ")+QString::number(lives));
    setPos(10, 40);
    setScale(2);
    setDefaultTextColor(Qt::green);
}

void LivesManager::decreaseLives()
{
    lives--;
    setPlainText(QString("Lives: ")+QString::number(lives));
}

void LivesManager::resetLives()
{
    lives = MAX_LIVES;
    setPlainText(QString("Lives: ")+QString::number(lives));
}

int LivesManager::getLives()
{
    return lives;
}

void LivesManager::increaseLives(int value)
{
    lives += value;
    setPlainText(QString("Lives: ")+QString::number(lives));
}

