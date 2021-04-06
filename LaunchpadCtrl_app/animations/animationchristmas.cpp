#include "animationchristmas.h"

AnimationChristmas::AnimationChristmas()
{
    _animationName = " Christmass Tree";
}

void AnimationChristmas::Projection()
{
    const byte *tree = SymbolGenerator::GetInstance().GetChristmassTree();

    Clear();

    int i = 0;
    while (tree[i] != 0x00)
        SetLED(tree[i++], 3 << 4);

    byte last = 0x44;
    byte key;

    while (_running)
    {
        while (true && _running)
        {
            key = tree[(GetRandomInt() % i)];
            if (last < key - 6 || last > key + 6)
            {
                last = key;
                break;
            }
        }

        byte color = 0x30;

        if (GetRandomInt() % 9 == 0)
            color = 0x03;

        SetLED(key, color);
        AnimationPause(25, 2500);
    }
}
