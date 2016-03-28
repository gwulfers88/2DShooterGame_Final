#include "bossattackpassivestate.h"
#include "game.h"

extern Game* game;

BossAttackPassiveState::BossAttackPassiveState(EnemyBoss *boss, QGraphicsScene *scene)
    : BossBaseState(boss)
{

}

void BossAttackPassiveState::OnEnterState()
{
    healthOnEnter = enemyBoss->getLives();
    attackTimer = 0;
    attackRate = (rand() % 2) + 3;
}

void BossAttackPassiveState::OnUpdate()
{
    if(game->getPlayer()->x() >
            enemyBoss->x() + game->getPlayer()->boundingRect().width())
    {
        enemyBoss->setPos(enemyBoss->x() + enemyBoss->getSpeed() * 0.5f,
                          enemyBoss->y());
    }
    else if(game->getPlayer()->x() <
            enemyBoss->x() + game->getPlayer()->boundingRect().width())
    {
        enemyBoss->setPos(enemyBoss->x() - enemyBoss->getSpeed() * 0.5f,
                          enemyBoss->y());
    }

    float dt = 0.06f;

    attackTimer += dt;

    if(attackTimer > attackRate)
    {
        enemyBoss->Shoot();
        attackTimer = 0;
    }

    //TODO: Change to angry state after he loses certain % of the health
    if( enemyBoss->getLives() <= healthOnEnter * 0.25f)
    {
        ToAttackAgressiveState();
    }
}

