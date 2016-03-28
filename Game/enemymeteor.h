#ifndef ENEMYMETEOR_H
#define ENEMYMETEOR_H

#include "enemybase.h"

class EnemyMeteor : public EnemyBase
{
public:
    EnemyMeteor(QString filename, int maxLives = 3);
    void Move() override;
};

#endif // ENEMYMETEOR_H
