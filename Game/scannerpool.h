#ifndef SCANNERPOOL_H
#define SCANNERPOOL_H

#include <QList>
#include <QGraphicsScene>
#include <QString>
#include "enemyscanner.h"

class ScannerPool
{
public:
    ScannerPool(int minSize, QGraphicsScene *scene, QString filename);
    void InitializePool();
    void SpawnObject(float X, float Y);
    int getLiveCount();
    void destroyAll();

protected:
    int size;
    int liveCount;

    QList<EnemyScanner*> pool;
    QGraphicsScene *scene;

    QString filename;

};

#endif // SCANNERPOOL_H
