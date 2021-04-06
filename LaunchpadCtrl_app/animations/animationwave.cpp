#include "animationwave.h"

AnimationWave::AnimationWave()
{
    _animationName = " WAVE";
}

void AnimationWave::Projection()
{
    Clear();

    while (_running)
    {
        byte **allLeds = SymbolGenerator::GetInstance().GetLaunchpadButtons();

        for (int i = 0; i < 8 && _running; i++)
        {
            for (unsigned int key = allLeds[i][0]; key < allLeds[i][1]; key++)
            {
                SetLED(key, 0x30);
            }

            AnimationPause(30, 4500);
        }

        Clear();
        AnimationPause(100, 0);

        for (int i = 0; i < 8 && _running; i++)
        {
            SetLED(allLeds[0][0] + i, 0x03);
            SetLED(allLeds[1][0] + i, 0x03);
            SetLED(allLeds[2][0] + i, 0x03);
            SetLED(allLeds[3][0] + i, 0x03);
            SetLED(allLeds[4][0] + i, 0x03);
            SetLED(allLeds[5][0] + i, 0x03);
            SetLED(allLeds[6][0] + i, 0x03);
            SetLED(allLeds[7][0] + i, 0x03);

            AnimationPause(30, 4500);
        }

        Clear();
        AnimationPause(400, 0);
    }
}
