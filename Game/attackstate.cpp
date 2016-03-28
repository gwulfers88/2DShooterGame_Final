#include "attackstate.h"

#include <QDebug>

AttackState::AttackState(EnemyScanner *scanner, QGraphicsScene *scene)
    : BaseState(scanner)
{
    this->scene = scene;
    laserPool = EnemyLaserPool(3, scene);
    laserPool.InitializePool();

    blasters = new SoundManager("SFX/scanner_blasters.wav");
}

void AttackState::OnEnterState()
{
    dt = 0;
    shots = 0;
}

void AttackState::OnUpdate()
{
    float t = 1/((1.0f/60.0f) * 1000.0f);

    dt += t;

    if(dt > 1.f)
    {
        laserPool.SpawnObject(enemyScanner->x() + (enemyScanner->boundingRect().width()/2),
                              enemyScanner->y() + (enemyScanner->boundingRect().height()/2));

        blasters->PlayOneShot();

        dt = 0;
        shots++;
    }

    if(shots == 3)
    {
        ToScan();
    }
}

