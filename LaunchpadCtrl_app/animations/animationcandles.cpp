#include "animationcandles.h"

AnimationCandles::AnimationCandles()
{
    _animationName = " Candles";
}

void AnimationCandles::Projection()
{
    const byte *candles = SymbolGenerator::GetInstance().GetCandles();
    const byte *lights = SymbolGenerator::GetInstance().GetLights();

    Clear();

    while (_running)
    {
        for (unsigned int i = 0; i < 10 && _running; i+=5)
        {
            SetLED(lights[i+1], 0x33);
            SetLED(lights[i+2], 0x33);
            SetLED(lights[i+3], 0x33);
            SetLED(lights[i+4], 0x33);
            SetLED(lights[i+5], 0x33);

            AnimationPause(50, 2500);

            SetLED(lights[i+1], 0x00);
            SetLED(lights[i+2], 0x00);
            SetLED(lights[i+3], 0x00);
            SetLED(lights[i+4], 0x00);
            SetLED(lights[i+5], 0x00);
        }

        int i = 0;
        while (candles[i] != 0x00)
        {
            SetLED(candles[i++], 0x30);
        }
    }
}
