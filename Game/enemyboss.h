#ifndef ENEMYBOSS_H
#define ENEMYBOSS_H

#include "enemybase.h"
#include "enemylaserpool.h"
#include "scannerpool.h"
#include "soundmanager.h"

class BossBaseState;
class BossSpawnState;
class BossAttackPassiveState;
class BossAttackAgressiveState;

class EnemyBoss : public EnemyBase
{
public:
    EnemyBoss(QString filename, int maxLives, QGraphicsScene* scene);

    BossBaseState* currentState;
    BossSpawnState* spawnState;
    BossAttackPassiveState* attackPassiveState;
    BossAttackAgressiveState* attackAgressiveState;

    void ChangeState(BossBaseState* newState);
    int getLives();
    void Shoot();
    void setScanners(ScannerPool* scannerPool);
    void spawnScanner();

protected:
    EnemyLaserPool* laserPool;
    ScannerPool* scanners;
    SoundManager* blasters;

public slots:
    void Update() override;
};

#endif // ENEMYBOSS_H
