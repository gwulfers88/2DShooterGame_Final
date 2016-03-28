#include "spawnstate.h"

SpawnState::SpawnState(EnemyScanner *scanner)
    : BaseState(scanner)
{

}

void SpawnState::OnEnterState()
{
    toScanRate = rand() % 9;
    toScanTimer = 0;
}

void SpawnState::OnUpdate()
{
    toScanTimer += 0.06f;

    if(toScanTimer >= toScanRate)
    {
        ToScan();
    }

    enemyScanner->setPos(enemyScanner->x(), enemyScanner->y() + enemyScanner->getSpeed());
}

