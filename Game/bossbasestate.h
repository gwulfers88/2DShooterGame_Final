#ifndef BOSSBASESTATE_H
#define BOSSBASESTATE_H

#include "enemyboss.h"

class BossBaseState
{
public:
    BossBaseState(EnemyBoss* boss);

    virtual void OnEnterState();
    virtual void OnUpdate();

    void ToSpawnState();
    void ToAttackPassiveState();
    void ToAttackAgressiveState();

protected:
    EnemyBoss* enemyBoss;
};

#endif // BOSSBASESTATE_H
