#include "enemyboss.h"
#include "bossspawnstate.h"
#include "bossattackpassivestate.h"
#include "bossattackagressivestate.h"

EnemyBoss::EnemyBoss(QString filename, int maxLives, QGraphicsScene *scene)
    : EnemyBase(filename, maxLives)
{
    speed = 1.5f;
    setIsAlive(true);

    laserPool = new EnemyLaserPool(5, scene);
    laserPool->InitializePool();

    blasters = new SoundManager("SFX/scanner_blasters.wav");

    spawnState = new BossSpawnState(this);
    attackPassiveState = new BossAttackPassiveState(this, scene);
    attackAgressiveState = new BossAttackAgressiveState(this);

    scoreValue = 500;

    ChangeState(spawnState);
}

void EnemyBoss::ChangeState(BossBaseState *newState)
{
    currentState = newState;
    currentState->OnEnterState();
}

int EnemyBoss::getLives()
{
    return lives;
}

void EnemyBoss::Shoot()
{
    laserPool->SpawnObject(x() + boundingRect().width()/2,
                           y() + boundingRect().height()/2);

    blasters->PlayOneShot();
}

void EnemyBoss::setScanners(ScannerPool *scannerPool)
{
    scanners = scannerPool;
}

void EnemyBoss::spawnScanner()
{
    scanners->SpawnObject(x(), y());
}

void EnemyBoss::Update()
{
    if(isAlive)
    {
        currentState->OnUpdate();
        CheckCollision();
    }
}

