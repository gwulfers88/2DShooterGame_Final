#ifndef ENEMYLASER_H
#define ENEMYLASER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QString>

class EnemyLaser :
        public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit EnemyLaser(QObject *parent = 0);
    bool getIsAlive();
    void setIsAlive(bool alive);
    QString getTag() { return "Laser"; }

signals:

public slots:
    void Update();

private:
    float vY;
    float speed;
    bool isAlive;
    QTimer *deltaTime;
};

#endif // ENEMYLASER_H
