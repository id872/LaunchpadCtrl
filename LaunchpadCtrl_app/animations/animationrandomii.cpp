#include "animationrandomii.h"

AnimationRandomII::AnimationRandomII()
{
    _animationName = " Random 2";
}

void AnimationRandomII::Projection()
{
    Clear();

    while (_running)
    {
        byte color = 0x03;

        if(GetRandomInt() % 2 == 0)
            color = 0x30;

        SetLED(GetRandomKey(), color);
        AnimationPause(5, 700);
    }
}
