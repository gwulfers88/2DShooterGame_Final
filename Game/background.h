#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Background :
        public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Background();
    float GetHeight();
    void Update(float t);

private:
    float vy;
    float height;
    float scrollSpeed;
};

#endif // BACKGROUND_H
