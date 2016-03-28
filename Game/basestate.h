#ifndef BASESTATE_H
#define BASESTATE_H

#include "enemyscanner.h"

class BaseState
{
public:
    BaseState(EnemyScanner *scanner);

    virtual void OnEnterState();
    virtual void OnUpdate();

    void ToScan();
    void ToSleep();
    void ToAttack();

protected:
    EnemyScanner *enemyScanner;
};

#endif // BASESTATE_H
