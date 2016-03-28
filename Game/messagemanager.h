#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include <QGraphicsTextItem>

class MessageManager : public QGraphicsTextItem
{
public:
    MessageManager();
    void setText(QString text);

protected:
    QString text;
};

#endif // MESSAGEMANAGER_H
