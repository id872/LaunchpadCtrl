#include "animationbase.h"
#include "launchpadapi.h"
#include <unistd.h>

AnimationBase::~AnimationBase()
{
    Stop();
    usleep(1000 * 25);
}

void AnimationBase::SetLED(byte btnID, byte color)
{
    LaunchpadAPI::GetInstance().SetLED(btnID, color);
}

void AnimationBase::AnimationPause(const unsigned int miliSec, const unsigned int spdFactor)
{
    usleep((1000 * miliSec) + (_animationSpeed * spdFactor));
}

void AnimationBase::Clear()
{
    LaunchpadAPI::GetInstance().SetAllButtonsOff();
}

byte AnimationBase::GetRandomColor()
{
    byte green = (GetRandomInt() % 3);
    byte red = (GetRandomInt() % 3);

    if (green == 0 && red == 0)
    {
        if (GetRandomInt() % 1 == 1)
            green = 3;
        else
            red = 3;
    }

    return ((green << 4) | red);
}

byte AnimationBase::GetRandomKey()
{
    byte **allLeds = SymbolGenerator::GetInstance().GetLaunchpadButtons();

    if (allLeds == NULL)
        return 0;

    byte rand_i = GetRandomInt() % 8;
    byte min = allLeds[rand_i][0];
    byte max = allLeds[rand_i][1] + 1;

    return (min + (GetRandomInt() % (max - min)));
}

void AnimationBase::Start()
{
    if (!_running)
    {
        _running = true;
        QtConcurrent::run(this, &AnimationBase::Projection);
    }
}

void AnimationBase::Stop()
{
    _running = false;
}
