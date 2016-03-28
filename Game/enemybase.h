#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QString>
#include <QTimer>

class EnemyBase :
        public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    EnemyBase(QString filename, int maxLives = 3);
    virtual QString getTag() { return "Enemy"; }
    bool getIsAlive();
    void setIsAlive(bool alive);
    void kill();
    float getSpeed();

protected:
    float vx;
    float vy;
    bool isAlive;
    int lives;
    const int MAX_LIVES;
    int scoreValue;
    float speed;

    QTimer *timer;

    virtual void CheckCollision();
    virtual void Move();

signals:

public slots:
    virtual void Update();
};

#endif // ENEMYBASE_H
