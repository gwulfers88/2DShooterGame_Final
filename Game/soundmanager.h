#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QMediaPlayer>
#include <QObject>

class SoundManager : public QObject
{
    Q_OBJECT
public:
    SoundManager(QString filename, QObject* parent = 0);

    void SetSound(QString filename);
    void PlayOneShot();
    void Play();
    void Reset();
    void Stop();

protected:
    QString filename;
    QMediaPlayer* sound;
};

#endif // SOUNDMANAGER_H
