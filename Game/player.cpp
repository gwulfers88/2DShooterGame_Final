#include "player.h"
#include "enemybase.h"
#include "enemylaser.h"

#include <QPixmap>
#include <QTimer>
#include <QDebug>

Player::Player(QGraphicsScene *scene, LivesManager* lives)
{
    this->scene = scene;
    this->lives = lives;

    Up = false;
    Down = false;
    Right = false;
    Left = false;
    Shoot = false;

    setPixmap(QPixmap(":/sprites/Sprites/fighter.png"));

    width = boundingRect().width();
    height = boundingRect().height();
    centerX = (float)width * 0.5f;
    centerY = (float)height * 0.5f;
    power = 40.0f;
    vx = 0;
    vy = 0;
    drag = 0.05f;
    ShootTimer = 0;
    ShootRate = 0.75f;

    laserPool = LaserPool(2, this->scene);
    laserPool.InitializePool();

    laserShot = new SoundManager("SFX/player_laser.wav", this);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        Up = true;
    }
    if(event->key() == Qt::Key_S)
    {
        Down = true;
    }
    if(event->key() == Qt::Key_A)
    {
        Left = true;
    }
    if(event->key() == Qt::Key_D)
    {
        Right = true;
    }

    if(event->key() == Qt::Key_Space)
    {
        Shoot = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        Up = false;
    }
    if(event->key() == Qt::Key_S)
    {
        Down = false;
    }
    if(event->key() == Qt::Key_A)
    {
        Left = false;
    }
    if(event->key() == Qt::Key_D)
    {
        Right = false;
    }
    if(event->key() == Qt::Key_Space)
    {
        Shoot = false;
    }
}

void Player::CheckBounds(float minX, float minY, float maxX, float maxY)
{
    //LEFT CHECK
    if(x() <= minX)
    {
        setX(minX);
        vx = 0;
    }
    //TOP CHECK
    if(y() <= minY)
    {
        setY(minY);
        vy = 0;
    }

    //RIGHT CHECK
    if(x() >= maxX - width)
    {
        setX(maxX - width);
        vx = 0;
    }

    //DOWN CHECK
    if(y() >= maxY - height)
    {
        setY(maxY - height);
        vy = 0;
    }
}

void Clampf(float &value, float min, float max)
{
    if(value > max)
        value = max;
    if(value < min)
        value = min;
}

void Player::Update(float t)
{
    //Direction Vector
    float dx = 0;   //Reset every frame
    float dy = 0;   //Reset every frame

    //Increment the shoot timer.
    ShootTimer += t;

    //NOTE: Keyboard input
    if(Up)
    {
        dy = -1;    //set direction up
    }
    if(Down)
    {
        dy = 1; //set direction down
    }
    if(Left)
    {
        dx = -1;    //set direction left
    }
    if(Right)
    {
        dx = 1; //set direction right
    }

    //SHOOT!!
    if(Shoot && ShootTimer >= ShootRate)
    {
        laserPool.SpawnObject(x() + centerX / 2, y() - centerY);
        ShootTimer = 0;

        //Play laser sound
        laserShot->PlayOneShot();
    }

    //NOTE: Check Bounds
    CheckBounds(0, 0, 800, 600);

    dx *= power;    //scale direction vector by speed
    dy *= power;

    //Drag coeficient
    vx += dx * t;   //Add the direction scaled by the time to the velocity vector.
    vy += dy * t;

    //Clamp X and Y velocity by our Speed
    Clampf(vx, -power, power);
    Clampf(vy, -power, power);

    //Set position and scale it by drag
    setPos(x() + vx * drag, y() + vy * drag);

    /// Check for collision with enemies and lasers
    for( int i = 0; i < this->collidingItems().size(); ++i)
    {
        EnemyBase* enemy = dynamic_cast<EnemyBase*>(this->collidingItems()[i]);

        if(enemy)
        {
            lives->decreaseLives();
            enemy->kill();

            break;
        }

        EnemyLaser* enemyLaser = dynamic_cast<EnemyLaser*>(this->collidingItems()[i]);

        if(enemyLaser)
        {
            lives->decreaseLives();
            enemyLaser->setIsAlive(false);

            break;
        }
    }
}
