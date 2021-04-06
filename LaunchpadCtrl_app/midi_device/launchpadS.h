#ifndef LAUNCHPADDEVICE_H
#define LAUNCHPADDEVICE_H
#include "midi_device/mididevice.h"

typedef unsigned char byte;

class LaunchpadS : public MidiDevice
{
public:
    LaunchpadS();
    bool IsUpPressed();
    bool IsDownPressed();
    void SetAllButtonsOn() { SendMessage(176, 0, 127); }
    void SetAllButtonsOff() { SendMessage(176, 0, 0); }
    void SetLED(byte, byte);

private:
    void Listener();
    void WelcomeBlink(const unsigned int);

    bool _upPressed = false;
    bool _downPressed = false;
};

#endif // LAUNCHPADDEVICE_H
