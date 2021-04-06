#include "animator.h"
#include "animations/animationrandom.h"
#include "animations/animationheart.h"
#include "animations/animationsnake.h"
#include "animations/animationwave.h"
#include "animations/animationcandles.h"
#include "animations/animationstandby.h"
#include "animations/animationsound.h"
#include "animations/animationrandomii.h"
#include "animations/animationchristmas.h"
#include "launchpadapi.h"
#include "audio/MicInput.h"
#include <unistd.h>
#include <QtConcurrent/QtConcurrent>

Animator::Animator()
{
    _currentAnimation = 0;

    _threadEnabled = true;
    _micInput = new MicInput();

    _animations.append(new AnimationStandby());
    _animations.append(new AnimationRandom());
    _animations.append(new AnimationRandomII());
    _animations.append(new AnimationChristmas());
    _animations.append(new AnimationHeart());
    _animations.append(new AnimationSnake());
    _animations.append(new AnimationWave());
    _animations.append(new AnimationCandles());
    _animations.append(new AnimationSound(_micInput));

    QtConcurrent::run(this, &Animator::animationThread);
}

Animator::~Animator()
{
    _threadEnabled = false;

    if (LaunchpadAPI::GetInstance().IsInitialized())
    {
        StopCurrent();
    }
    if (_micInput != nullptr)
        delete _micInput;

    for (int i = 0; i < _animations.count(); i++) {
        if (_animations[i] != nullptr)
            delete _animations[i];
    }
    _animations.clear();
}

QList<QString> Animator::GetNames()
{
    QList<QString> names;

    for (int i = 0; i < _animations.count(); i++)
    {
        names << _animations[i]->GetName();
    }

    return names;
}

void Animator::StopCurrent()
{
    _animations[currentAnimation()]->Stop();
    usleep(1000 * 5);
}

void Animator::animationThread()
{
    while (_threadEnabled)
    {
        if (LaunchpadAPI::GetInstance().IsUpPressed())
        {
            setNextAnimation();
        }
        else if (LaunchpadAPI::GetInstance().IsDownPressed())
        {
            setPrevAnimation();
        }

        usleep(1000 * 10);
    }
}

unsigned int Animator::currentAnimation() const
{
    return _currentAnimation;
}

void Animator::setCurrentAnimation(unsigned int currentAnimation)
{
    if (_currentAnimation != currentAnimation)
    {
        StopCurrent();
        _currentAnimation = currentAnimation;
        _animations[currentAnimation]->Start();
    }
}

void Animator::setNextAnimation()
{
    setCurrentAnimation((currentAnimation() + 1) % _animations.count());
}

void Animator::setPrevAnimation()
{
    if (_currentAnimation == 0)
        setCurrentAnimation(_animations.count() - 1);
    else
        setCurrentAnimation((currentAnimation() - 1) % _animations.count());
}

void Animator::SetAnimationSpeed(unsigned int spd)
{
    _animations[currentAnimation()]->SetSpeed(spd);
}
