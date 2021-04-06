#include "animationbirthday.h"

AnimationBirthday::AnimationBirthday()
{
    _animationName = " 29th birthday";
}

void AnimationBirthday::Projection()
{
    const byte *buttons = SymbolGenerator::GetInstance().GetTwentyNine();
    const byte *heart = SymbolGenerator::GetInstance().GetHeart();

    if (buttons == NULL || heart == NULL)
        return;

    int counter = 0;

    Clear();

    while (_running)
    {
        byte color;

        while (counter++ < 25 && _running)
        {
            color = GetRandomColor();

            int i = 0;
            while (buttons[i] != 0x00)
            {
                SetLED(buttons[i++], color);
            }

            AnimationPause(50, 2500);
        }

        counter = 0;

        while (counter++ < 25 && _running)
        {
            int i = 0;
            while (buttons[i] != 0x00)
            {
                if (i % 8 == 0)
                {
                    color = 0x03;
                    if (GetRandomInt() % 2 == 0)
                        color = 0x30;
                }

                SetLED(buttons[i++], color);
            }
            AnimationPause(50, 2500);
        }

        counter = 0;

        while (counter++ < 25 && _running)
        {
            int i = 0;
            while (buttons[i] != 0x00)
            {
                color = GetRandomColor();

                SetLED(buttons[i++], color);
            }
            AnimationPause(50, 2500);
        }

        counter = 0;
        Clear();

        while (counter++ < 5 && _running)
        {
            int i = 0;
            while (heart[i] != 0x00)
            {
                SetLED(heart[i++], 0x3);
            }

            AnimationPause(((GetRandomInt() % 400) + 50), 500);
            Clear();
            AnimationPause(((GetRandomInt() % 400) + 50), 500);
        }

        counter = 0;

        Clear();
    }
}
