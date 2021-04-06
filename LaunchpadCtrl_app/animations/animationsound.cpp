#include "animationsound.h"
#include "audio/MicInput.h"

AnimationSound::AnimationSound(MicInput *micInput)
{
    _animationName = " Mic sound visualization";
    _micInput = micInput;
    _soundLevelThresholds = new float[8]{
        0.55, 0.6, 0.65, 0.7, 0.78, 0.83, 0.87, 0.91
    };
}

void AnimationSound::lightRow(int row)
{
    byte **allButtons = SymbolGenerator::GetInstance().GetLaunchpadButtons();

    for (int r = 0; r < row; r++)
    {
        for (int i = 0; i < 8 && _running; i++)
        {
            SetLED(allButtons[r][0] + i, GetRandomColor());
        }
    }
}

void AnimationSound::Projection()
{
    while (_running) {
        for (int i = 0; i < 8; i++)
        {
            if (_micInput->getCurrentSoundLevel() > _soundLevelThresholds[i])
            {
                lightRow(i + 1);
            }
        }

        AnimationPause(10, 1000);
        Clear();
    }
}
