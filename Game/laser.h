#ifndef LASER_H
#define LASER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QString>

class laser :
        public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit laser(QObject *parent = 0);
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

#endif // LASER_H
