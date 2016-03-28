#ifndef BOSSATTACKAGRESSIVESTATE_H
#define BOSSATTACKAGRESSIVESTATE_H

#include "bossbasestate.h"

class BossAttackAgressiveState : public BossBaseState
{
public:
    BossAttackAgressiveState(EnemyBoss* boss);

    void OnEnterState() override;
    void OnUpdate() override;

protected:
    float getDistRate;
    float getDistTimer;

    float attackRate;
    float attackTimer;

    float spawnRate;
    float spawnTimer;
    int spawnLimit;
    int spawnCount;
};

#endif // BOSSATTACKAGRESSIVESTATE_H
