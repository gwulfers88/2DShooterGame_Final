#ifndef ATTACKSTATE_H
#define ATTACKSTATE_H

#include "basestate.h"
#include "enemylaserpool.h"
#include "soundmanager.h"

class AttackState : public BaseState
{
public:
    AttackState(EnemyScanner* scanner, QGraphicsScene* scene);
    void OnEnterState() override;
    void OnUpdate() override;

protected:
    float dt;
    int shots;

    QGraphicsScene* scene;
    EnemyLaserPool laserPool;
    SoundManager* blasters;
};

#endif // ATTACKSTATE_H
