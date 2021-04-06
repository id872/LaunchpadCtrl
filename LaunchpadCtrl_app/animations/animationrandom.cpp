#include "animationrandom.h"

AnimationRandom::AnimationRandom()
{
    _animationName = " Random";
}

void AnimationRandom::Projection()
{
    Clear();

    while (_running)
    {
         SetLED(GetRandomKey(), GetRandomColor());
         AnimationPause(5, 700);
    }
}
