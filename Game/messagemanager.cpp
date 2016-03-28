#include "messagemanager.h"

MessageManager::MessageManager():
    QGraphicsTextItem()
{
    setText("MESSAGE: ");
    setScale(3);
    setPos(200, 10);
    setDefaultTextColor(Qt::green);
}


void MessageManager::setText(QString text)
{
    setPlainText(text);
}
