#ifndef SPAWNSTATE_H
#define SPAWNSTATE_H

#include "basestate.h"

class SpawnState : public BaseState
{
public:
    SpawnState(EnemyScanner *scanner);
    void OnEnterState() override;
    void OnUpdate() override;

protected:
    float toScanTimer;
    float toScanRate;
};

#endif // SPAWNSTATE_H
