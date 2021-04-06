#include "animationheart.h"

AnimationHeart::AnimationHeart()
{
    _animationName = " Heart";
}

void AnimationHeart::Projection()
{
    const byte *symbol = SymbolGenerator::GetInstance().GetHeart();

    while (_running)
    {
        Clear();
        AnimationPause(25, 2500);
        int i = 0;

        while (symbol[i] != 0x00 && _running)
        {
            SetLED(symbol[i++], 3);
            AnimationPause(25, 2500);
        }
    }
}
