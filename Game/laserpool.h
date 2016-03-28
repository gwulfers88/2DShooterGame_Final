#ifndef LASERPOOL_H
#define LASERPOOL_H

#include <QList>
#include <QGraphicsScene>
#include "laser.h"

class LaserPool
{
public:
    LaserPool(int minSize = 2, QGraphicsScene *scene = 0);
    void InitializePool();
    void SpawnObject(float X, float Y);

protected:
    int size;
    QList<laser*> pool;
    QGraphicsScene *scene;
};

#endif // LASERPOOL_H
