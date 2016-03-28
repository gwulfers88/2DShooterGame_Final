#ifndef LIVESMANAGER_H
#define LIVESMANAGER_H

#include <QGraphicsTextItem>

class LivesManager : public QGraphicsTextItem
{
public:
    LivesManager();
    void decreaseLives();
    void resetLives();

    int getLives();
    void increaseLives(int value);

protected:
    int lives;
    const int MAX_LIVES;
};

#endif // LIVESMANAGER_H
