#include "enemymeteor.h"

EnemyMeteor::EnemyMeteor(QString filename, int maxLives)
    : EnemyBase(filename, maxLives)
{

}

float rot = rand() % 5;

void EnemyMeteor::Move()
{
    float t = 0.06f;

    EnemyBase::Move();

    rot += t;

    setRotation(rot + 2);
}

