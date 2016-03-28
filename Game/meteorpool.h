#ifndef METEORPOOL_H
#define METEORPOOL_H

#include <QList>
#include <QGraphicsScene>
#include <QString>
#include "enemymeteor.h"

class MeteorPool
{
public:
    MeteorPool(int minSize, QGraphicsScene *scene, QString filename);
    void InitializePool();
    void SpawnObject(float X, float Y);

protected:
    int size;
    QList<EnemyMeteor*> pool;
    QGraphicsScene *scene;

    QString filename;

};

#endif // METEORPOOL_H
