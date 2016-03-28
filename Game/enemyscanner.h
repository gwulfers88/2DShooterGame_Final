#ifndef ENEMYSCANNER_H
#define ENEMYSCANNER_H

#include "enemybase.h"

class SpawnState;
class ScanState;
class AttackState;
class BaseState;

class EnemyScanner : public EnemyBase
{
public:
    EnemyScanner(QString filename, int maxLives, QGraphicsScene *scene);

    BaseState* currentState;
    SpawnState* spawnState;
    ScanState* scanState;
    AttackState* attackState;

    void ChangeState(BaseState* newState);

public slots:
    void Update() override;
};

#endif // ENEMYSCANNER_H
