#include "midi_device/mididevice.h"
#include "midi_device/RtMidi.h"
#include <unistd.h>

MidiDevice::MidiDevice(const char* name)
{
    _devName = name;
    _initialized = InitializeMidiOut() && InitializeMidiIn();

    if (_initialized)
    {
        for (int i = 0; i < 3; i++)
            _txMsg.push_back(0);

        _listen = true;
    }
}

MidiDevice::~MidiDevice()
{
    DeInitialize();
}

void MidiDevice::DeInitialize()
{
    if (_initialized)
    {
        _listen = false;
        usleep(1000 * 50);
        delete _midiIn;
        delete _midiOut;
    }
}

bool MidiDevice::InitializeMidiOut()
{
    _midiOut = new RtMidiOut();

    int mpc = _midiOut->getPortCount();

    for (int i = 0; i < mpc; i++)
    {
        std::string port_name = _midiOut->getPortName(i);

        if (port_name.find(_devName) != std::string::npos)
        {
            _midiOut->openPort(i);
            return true;
        }
    }

    return false;
}

bool MidiDevice::InitializeMidiIn()
{
    _midiIn = new RtMidiIn();

    int mpc = _midiIn->getPortCount();

    for (int i = 0; i < mpc; i++)
    {
        std::string port_name = _midiIn->getPortName(i);

        if (port_name.find(_devName) != std::string::npos)
        {
            _midiIn->openPort(i);
            return true;
        }
    }

    return false;
}

void MidiDevice::SendMessage()
{
    if (_newData == true)
    {
        _midiOut->sendMessage(&_txMsg);
        _newData = false;
    }
}

void MidiDevice::SendMessage(byte h, byte m, byte l)
{
    if (h != _txMsg[0] ||
        m != _txMsg[1] ||
        l != _txMsg[2])
    {
        _txMsg[0] = h;
        _txMsg[1] = m;
        _txMsg[2] = l;
        _newData = true;

        SendMessage();
    }
}

void MidiDevice::ReadMessage()
{
    _midiIn->getMessage(&_rxMsg);
}

const MIDI_Message MidiDevice::GetRxMessage() const
{
    return _rxMsg;
}
