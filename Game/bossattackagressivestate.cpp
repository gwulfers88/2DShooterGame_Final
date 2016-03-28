#include "bossattackagressivestate.h"
#include "game.h"

extern Game* game;

BossAttackAgressiveState::BossAttackAgressiveState(EnemyBoss *boss)
    : BossBaseState(boss)
{

}

void BossAttackAgressiveState::OnEnterState()
{
    getDistRate = 10.0f;
    attackRate = 2.0f;
    spawnRate = 15.0f;

    getDistTimer = 0;
    attackTimer = 0;
    spawnTimer = 0;

    spawnLimit = 3;
    spawnCount = 0;
}

void BossAttackAgressiveState::OnUpdate()
{
    float dt = 0.06f;

    getDistTimer += dt;

    if( getDistTimer < getDistRate)
    {
        enemyBoss->setPos(enemyBoss->x(), enemyBoss->y() - enemyBoss->getSpeed());
    }
    else
    {
        //Shoot the player and follow him.
        if(game->getPlayer()->x() >
                enemyBoss->x() + game->getPlayer()->boundingRect().width())
        {
            enemyBoss->setPos(enemyBoss->x() + enemyBoss->getSpeed() * 2,
                              enemyBoss->y());
        }
        else if(game->getPlayer()->x() <
                enemyBoss->x() + game->getPlayer()->boundingRect().width())
        {
            enemyBoss->setPos(enemyBoss->x() - enemyBoss->getSpeed() * 2, enemyBoss->y());
        }

        attackTimer += dt;

        if(attackTimer > attackRate)
        {
            enemyBoss->Shoot();
            attackTimer = 0;
        }

        //Spawn Enemies
        spawnTimer += dt;

        if(spawnTimer > spawnRate)
        {
            if( spawnCount < spawnLimit)
            {
                enemyBoss->spawnScanner();
                spawnCount++;
            }
            spawnTimer = 0;
        }
    }
}

