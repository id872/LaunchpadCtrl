#ifndef ANIMATIONSOUND_H
#define ANIMATIONSOUND_H
#include "animationbase.h"

class MicInput;

class AnimationSound : public AnimationBase
{
public:
    AnimationSound(MicInput *);
    virtual void Projection();
private:
    void lightRow(int);

    float *_soundLevelThresholds = nullptr;
    MicInput *_micInput = nullptr;
};

#endif // ANIMATIONRANDOM_H
