#ifndef ANIMATION_H
#define ANIMATION_H
#include <QString>
#include <QtConcurrent/QtConcurrent>
#include "symbolgenerator.h"

typedef unsigned char byte;

class AnimationBase
{
public:
    AnimationBase(){ _animationSpeed = 0; }
    virtual ~AnimationBase();

    QString GetName() { return _animationName; }
    void SetSpeed(unsigned int spd) { _animationSpeed = spd; }
    void Start();
    void Stop();
    bool IsRunning() { return _running; }

    virtual void Projection() = 0;

protected:
    void AnimationPause(const unsigned int, const unsigned int);
    void Clear();
    byte GetRandomColor();
    byte GetRandomKey();
    quint32 GetRandomInt() { return QRandomGenerator::global()->generate(); }
    void SetLED(byte,byte);

    QString _animationName;
    unsigned int _animationSpeed;
    bool _running = false;
};

#endif // ANIMATION_H
