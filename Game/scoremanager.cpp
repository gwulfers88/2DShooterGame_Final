#include "scoremanager.h"

ScoreManager::ScoreManager()
{
    score = 0;
    setPlainText(QString("Score: ")+QString::number(score));
    setPos(10, 10);
    setScale(2);
    setDefaultTextColor(Qt::green);
}

void ScoreManager::increaseScore(int value)
{
    score += value;
    setPlainText(QString("Score: ")+QString::number(score));
}

void ScoreManager::resetScore()
{
    score = 0;
    setPlainText(QString("Score: ")+QString::number(score));
}

int ScoreManager::getScore()
{
    return score;
}

