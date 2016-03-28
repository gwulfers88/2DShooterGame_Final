#include "bossspawnstate.h"

BossSpawnState::BossSpawnState(EnemyBoss *boss)
    : BossBaseState(boss)
{

}

void BossSpawnState::OnEnterState()
{
    toAttackPassiveTimer = 0;
}

void BossSpawnState::OnUpdate()
{
    float dt = 0.06f;

    toAttackPassiveTimer += dt;

    if(toAttackPassiveTimer > 12.50f)
    {
        ToAttackPassiveState();
    }

    enemyBoss->setPos(enemyBoss->x(), enemyBoss->y() + enemyBoss->getSpeed());
}
