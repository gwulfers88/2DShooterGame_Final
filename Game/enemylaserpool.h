#ifndef ENEMYLASERPOOL_H
#define ENEMYLASERPOOL_H

#include <QList>
#include <QGraphicsScene>
#include "enemylaser.h"

class EnemyLaserPool
{
public:
    EnemyLaserPool(int minSize = 2, QGraphicsScene *scene = 0);
    void InitializePool();
    void SpawnObject(float X, float Y);

protected:
    int size;
    QList<EnemyLaser*> pool;
    QGraphicsScene *scene;
};

#endif // ENEMYLASERPOOL_H
