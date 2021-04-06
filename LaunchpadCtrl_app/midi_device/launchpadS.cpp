#include "midi_device/launchpadS.h"
#include <unistd.h>
#include <QtConcurrent/QtConcurrent>

LaunchpadS::LaunchpadS() : MidiDevice("Launchpad S")
{
    if (IsInitialized())
    {
        WelcomeBlink(2);
        QtConcurrent::run(this, &LaunchpadS::Listener);
    }
}

void LaunchpadS::WelcomeBlink(const unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
    {
        SendMessage(176, 0, 127);
        usleep(1000 * 80); //80ms
        SendMessage(176, 0, 0);
        usleep(1000 * 120);
    }
}

void LaunchpadS::Listener()
{
    while (IsListening())
    {
        ReadMessage();
        const MIDI_Message rx = GetRxMessage();

        if (rx.size() == 3 && rx[2] == 127)
        {
            if (rx[0] == 176 && rx[1] == 105)
                _upPressed = true;
            else if (rx[0] == 176 && rx[1] == 104)
                _downPressed = true;
        }

        usleep(1000 * 25);
    }
}

void LaunchpadS::SetLED(byte btnAddr, byte color)
{
    SendMessage(144, btnAddr, color);
}

bool LaunchpadS::IsUpPressed()
{
    if (_upPressed)
    {
        _upPressed = false;
        return true;
    }

    return false;
}

bool LaunchpadS::IsDownPressed()
{
    if (_downPressed)
    {
        _downPressed = false;
        return true;
    }

    return false;
}
