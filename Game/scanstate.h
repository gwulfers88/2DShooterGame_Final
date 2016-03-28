#ifndef SCANSTATE_H
#define SCANSTATE_H

#include "basestate.h"
#include "game.h"

extern Game* game;

class ScanState : public BaseState
{
public:
    ScanState(EnemyScanner *scanner);

    void OnEnterState() override;
    void OnUpdate() override;

protected:
    float xdir;
};

#endif // SCANSTATE_H
