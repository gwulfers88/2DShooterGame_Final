#ifndef BOSSSPAWNSTATE_H
#define BOSSSPAWNSTATE_H

#include "bossbasestate.h"

class BossSpawnState : public BossBaseState
{
public:
    BossSpawnState(EnemyBoss* boss);

    void OnEnterState() override;
    void OnUpdate() override;

protected:
    float toAttackPassiveTimer;
};

#endif // BOSSSPAWNSTATE_H
