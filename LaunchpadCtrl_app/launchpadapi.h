#ifndef LAUNCHPADAPI_H
#define LAUNCHPADAPI_H
#include <QList>

class Animator;
class LaunchpadS;

typedef unsigned char byte;

class LaunchpadAPI
{
public:
    static LaunchpadAPI& GetInstance()
    {
        static LaunchpadAPI instance;
        return instance;
    }
    void Deinitialize();
    bool IsInitialized() const { return _devInitialized; }
    void AnimationStop();
    void SetAnimation(unsigned int) const;
    void SetAnimationSpeed(unsigned int) const;
    void SetAllButtonsOn() const;
    void SetAllButtonsOff() const;
    void SetLED(byte,byte) const;
    QList<QString> GetAnimationNames() const;
    bool IsUpPressed() const;
    bool IsDownPressed() const;

private:
    LaunchpadAPI();
    bool _devInitialized;
    Animator *_launchpadAnimator = nullptr;
    LaunchpadS *_launchpadDev = nullptr;
};

#endif // LAUNCHPADAPI_H
