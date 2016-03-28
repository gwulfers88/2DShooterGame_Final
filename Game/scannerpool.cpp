#include "scannerpool.h"
#include <QDebug>

ScannerPool::ScannerPool(int minSize, QGraphicsScene *scene, QString filename)
{
    this->filename = filename;
    this->scene = scene;
    size = minSize; //initial number of lasers to be created.
}

void ScannerPool::InitializePool()
{
    //Initialize all lasers for our Object Pool
    for( int i = 0; i < size; ++i)
    {
        pool.push_back(new EnemyScanner(filename, 5, scene)); //Add laser
        pool.back()->setIsAlive(false);
        scene->addItem(pool.back());
    }
}

void ScannerPool::SpawnObject(float X, float Y)
{
    //Go through each list item
    //QT SUCKS!!! Cant even use a for( auto &iter : list ) loop!!!
    for(int i = 0; i < pool.size(); ++i)
    {
        //Find any that are dead
        if(!pool[i]->getIsAlive())
        {
            //Set the desired position and make them alive again.
            qDebug() << "pool object found\n";
            pool[i]->setPos(X, Y);
            pool[i]->ChangeState((BaseState*)pool[i]->spawnState);
            pool[i]->setIsAlive(true);
            return; //we're done!
        }
    }

    //If we found no active objects in our pool
    //Create a new one
    qDebug() << "Creating a new pool object\n";

    pool.push_back(new EnemyScanner(filename, 5, scene));
    pool.back()->setPos(X, Y);  //set position
    pool.back()->setIsAlive(true);  //make it alive
    scene->addItem(pool.back()); //add it to the scene
}

int ScannerPool::getLiveCount()
{
    for(int i = 0; i < pool.size(); ++i)
    {
        //Find any that are dead
        if(pool[i]->getIsAlive())
        {
            //Set the desired position and make them alive again.
            liveCount++;
        }
    }

    return liveCount;
}

void ScannerPool::destroyAll()
{
    for(int i = 0; i < pool.size(); ++i)
    {
        //Find any that are dead
        if(pool[i]->getIsAlive())
        {
            //Set the desired position and make them alive again.
            pool[i]->kill();
        }
    }
}
