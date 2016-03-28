#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "gamestate.h"
#include "player.h"
#include "background.h"

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    GameState* getState();
    Player* getPlayer();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Player *player;
    Background *bg1;
    Background *bg2;
    GameState* gameState;

    QTimer *timer;

signals:

public slots:
    void Update();
};

#endif // GAME_H
