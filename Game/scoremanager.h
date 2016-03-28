#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <QGraphicsTextItem>

class ScoreManager : public QGraphicsTextItem
{
public:
    ScoreManager();
    void increaseScore(int value);
    void resetScore();

    int getScore();

protected:
    int score;
};

#endif // SCOREMANAGER_H
