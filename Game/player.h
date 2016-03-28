#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QKeyEvent>
#include <QtMath>

#include "laserpool.h"
#include "livesmanager.h"
#include "soundmanager.h"

class Player :
        public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsScene *scene, LivesManager *lives);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void Update(float t);

    QString getTag() { return "Player"; }

protected:
    float vx;
    float vy;
    float centerX;
    float centerY;
    float drag;
    float ShootTimer;
    float ShootRate;
    float power;

    int width;
    int height;

    LivesManager* lives;
    LaserPool laserPool;

    QGraphicsScene *scene;
    SoundManager *laserShot;

    void CheckBounds(float minX, float minY, float maxX, float maxY);

private:
    bool Up;
    bool Down;
    bool Right;
    bool Left;
    bool Shoot;

public slots:

};

#endif // PLAYER_H
