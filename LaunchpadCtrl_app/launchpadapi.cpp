#include "animator.h"
#include "launchpadapi.h"
#include "midi_device/launchpadS.h"

LaunchpadAPI::LaunchpadAPI()
{
    _launchpadDev = new LaunchpadS();
    _devInitialized = _launchpadDev->IsInitialized();

    if (_devInitialized)
    {
        _launchpadAnimator = new Animator();
    }
}

void LaunchpadAPI::Deinitialize()
{
    if (!_devInitialized)
        return;

    SetAllButtonsOff();

    if (_launchpadAnimator != nullptr)
        delete _launchpadAnimator;
    if (_launchpadDev != nullptr)
        delete _launchpadDev;
}

QList<QString> LaunchpadAPI::GetAnimationNames() const
{
    return _launchpadAnimator->GetNames();
}

void LaunchpadAPI::SetAllButtonsOn() const
{
    _launchpadDev->SetAllButtonsOn();
}

void LaunchpadAPI::SetAllButtonsOff() const
{
    _launchpadDev->SetAllButtonsOff();
}

void LaunchpadAPI::SetAnimation(unsigned int a) const
{
    _launchpadAnimator->setCurrentAnimation(a);
}

void LaunchpadAPI::SetAnimationSpeed(unsigned int s) const
{
    _launchpadAnimator->SetAnimationSpeed(s);
}

void LaunchpadAPI::SetLED(byte btnID, byte color) const
{
    _launchpadDev->SetLED(btnID, color);
}

bool LaunchpadAPI::IsUpPressed() const
{
    return _launchpadDev->IsUpPressed();
}

bool LaunchpadAPI::IsDownPressed() const
{
    return _launchpadDev->IsDownPressed();
}
