#include "enemyscanner.h"
#include "scanstate.h"
#include "attackstate.h"
#include "spawnstate.h"

#include <QDebug>

EnemyScanner::EnemyScanner(QString filename, int maxLives, QGraphicsScene *scene)
    : EnemyBase(filename, maxLives)
{
    speed = 2.0f;
    setIsAlive(true);

    spawnState = new SpawnState(this);
    scanState = new ScanState(this);
    attackState = new AttackState(this, scene);

    scoreValue = (rand() % 40 ) + 50;
    ChangeState(spawnState);
}

void EnemyScanner::ChangeState(BaseState *newState)
{
    currentState = newState;
    currentState->OnEnterState();
}

void EnemyScanner::Update()
{
    if(isAlive)
    {
        currentState->OnUpdate();
        CheckCollision();
    }
}

