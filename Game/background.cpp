#include "background.h"

Background::Background()
{
    setPixmap(QPixmap(":/sprites/Sprites/space_bg.jpg"));

    vy = 0;
    scrollSpeed = 5.f;
    height = boundingRect().height();
}

float Background::GetHeight()
{
    return height;
}

void Background::Update(float t)
{
    //TODO: Make scrollable

    //TODO: Fix the white
}

