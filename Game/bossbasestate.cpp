#include "bossbasestate.h"

BossBaseState::BossBaseState(EnemyBoss *boss)
{
    enemyBoss = boss;
}

void BossBaseState::OnEnterState()
{

}

void BossBaseState::OnUpdate()
{

}

void BossBaseState::ToSpawnState()
{
    enemyBoss->ChangeState((BossBaseState*)enemyBoss->spawnState);
}

void BossBaseState::ToAttackPassiveState()
{
    enemyBoss->ChangeState((BossBaseState*)enemyBoss->attackPassiveState);
}

void BossBaseState::ToAttackAgressiveState()
{
    enemyBoss->ChangeState((BossBaseState*)enemyBoss->attackAgressiveState);
}
