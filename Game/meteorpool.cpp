#include "meteorpool.h"
#include <QDebug>

MeteorPool::MeteorPool(int minSize, QGraphicsScene *scene, QString filename)
{
    this->filename = filename;
    this->scene = scene;
    size = minSize; //initial number of lasers to be created.
}

void MeteorPool::InitializePool()
{
    //Initialize all lasers for our Object Pool
    for(int i = 0; i < size; ++i)
    {
        pool.push_back(new EnemyMeteor(filename)); //Add laser
        pool.back()->setIsAlive(false);
        scene->addItem(pool.back());
    }
}

void MeteorPool::SpawnObject(float X, float Y)
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
            pool[i]->setIsAlive(true);
            return; //we're done!
        }
    }

    //If we found no active objects in our pool
    //Create a new one
    qDebug() << "Creating a new pool object\n";

    pool.push_back(new EnemyMeteor(filename));
    pool.back()->setPos(X, Y);  //set position
    pool.back()->setIsAlive(true);  //make it alive
    scene->addItem(pool.back()); //add it to the scene
}
