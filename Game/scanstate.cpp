#include "scanstate.h"

#include <QDebug>
#include <math.h>

ScanState::ScanState(EnemyScanner *scanner)
    : BaseState(scanner)
{
    xdir = 0;
}

void ScanState::OnEnterState()
{
    qDebug() << "ScanState::OnEnterState()";
    xdir = 1;
}

void ScanState::OnUpdate()
{
    //CheckBounds
    if(enemyScanner->x() <= 0)
    {
        xdir = 1;
    }
    if(enemyScanner->x() >= 800 - enemyScanner->boundingRect().width())
    {
        xdir = -1;
    }

    // Scan for player
    enemyScanner->setPos(enemyScanner->x() + xdir * enemyScanner->getSpeed() , enemyScanner->y());

    if(enemyScanner->x() <= game->getPlayer()->x() + 5 &&
       enemyScanner->x() >= game->getPlayer()->x() - 5)
    {
        qDebug() << "ToAttack()";
        ToAttack();
    }
}
