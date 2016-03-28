#include "soundmanager.h"

SoundManager::SoundManager(QString filename, QObject *parent)
    : QObject(parent)
{
    this->filename = filename;
    sound = new QMediaPlayer();
    SetSound(filename);
}

void SoundManager::SetSound(QString filename)
{
    sound->setMedia(QUrl(QString("qrc:/sfx/")+QString(filename)));
}

void SoundManager::PlayOneShot()
{
    if(sound->state() == QMediaPlayer::PlayingState)
    {
        Reset();
    }
    else if(sound->state() == QMediaPlayer::StoppedState)
    {
        Play();
    }
}

void SoundManager::Play()
{
    sound->play();
}

void SoundManager::Reset()
{
    sound->setPosition(0);
}

void SoundManager::Stop()
{
    sound->stop();
}

