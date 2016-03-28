#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "meteorpool.h"
#include "scannerpool.h"
#include "scoremanager.h"
#include "livesmanager.h"
#include "messagemanager.h"
#include "soundmanager.h"

#include <QObject>

class GameState : public QObject
{
    Q_OBJECT
public:
    GameState(QGraphicsScene* scene, QObject * parent = 0);
    void spawnEnemies();
    float getDeltaTime();
    ScoreManager* getScore();
    LivesManager* getLives();
    MessageManager* getMessage();

protected:
    float meteorSpawnTimer;
    float meteorSpawnRate;

    float scannerSpawnTimer;
    float scannerSpawnRate;

    float t;

    MeteorPool *meteorPool;
    ScannerPool *scannerPool;
    ScoreManager *score;
    LivesManager *lives;
    MessageManager *message;

    SoundManager *actionMusic;  //Thanks to FoolBoyMedia action_music.wav for this sound!

    QGraphicsScene* scene;
};

#endif // GAMESTATE_H
