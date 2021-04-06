#include "animationsnake.h"

AnimationSnake::AnimationSnake()
{
    _animationName = " Snake";
}

void AnimationSnake::Projection()
{
    byte **allLeds = SymbolGenerator::GetInstance().GetLaunchpadButtons();
    byte animationColor = 0x03;

    if (allLeds == NULL)
        return;

    Clear();

    while (_running)
    {
        for (unsigned int i = 0; i < 8 && _running; i++)
        {
            if (i % 2 == 0)
            {
                animationColor = GetRandomColor();
                for (unsigned int key = allLeds[i][1]; key >= allLeds[i][0] && _running; key--)
                {
                    SetLED(key, animationColor);
                    AnimationPause(25, 2500);
                }
            }
            else
            {
                animationColor = GetRandomColor();
                for (unsigned int key = allLeds[i][0]; key <= allLeds[i][1] && _running; key++)
                {
                    SetLED(key, animationColor);
                    AnimationPause(25, 2500);
                }
            }
        }

        Clear();
    }
}
