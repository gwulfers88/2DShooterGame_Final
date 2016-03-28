#ifndef BOSSATTACKPASSIVESTATE_H
#define BOSSATTACKPASSIVESTATE_H

#include "bossbasestate.h"

class BossAttackPassiveState : public BossBaseState
{
public:
    BossAttackPassiveState(EnemyBoss *boss, QGraphicsScene* scene);

    void OnEnterState() override;
    void OnUpdate() override;

protected:
    float attackRate;
    float attackTimer;
    int healthOnEnter;
};

#endif // BOSSATTACKPASSIVESTATE_H
