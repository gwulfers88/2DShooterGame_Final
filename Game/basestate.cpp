#include "basestate.h"

BaseState::BaseState(EnemyScanner *scanner)
{
    enemyScanner = scanner;
}

void BaseState::OnEnterState()
{

}

void BaseState::OnUpdate()
{

}

void BaseState::ToScan()
{
    enemyScanner->ChangeState((BaseState*)enemyScanner->scanState);
}

void BaseState::ToSleep()
{

}

void BaseState::ToAttack()
{
    enemyScanner->ChangeState((BaseState*)enemyScanner->attackState);
}
