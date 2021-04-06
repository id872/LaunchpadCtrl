#include <vector>

typedef unsigned char byte;
typedef std::vector<unsigned char> MIDI_Message;

class RtMidiOut;
class RtMidiIn;

class MidiDevice
{
public:
    MidiDevice(const char *name);
    void SendMessage(byte,byte,byte);
    virtual ~MidiDevice();
    bool IsInitialized() const { return _initialized; }
    bool IsListening() const { return _listen; }

protected:
    void ReadMessage();
    const MIDI_Message GetRxMessage() const;

    MIDI_Message _txMsg;
    MIDI_Message _rxMsg;

private:
    void DeInitialize();
    bool InitializeMidiOut();
    bool InitializeMidiIn();
    void SendMessage();

    RtMidiOut *_midiOut = nullptr;
    RtMidiIn *_midiIn = nullptr;

    const char *_devName = nullptr;
    bool _initialized = false;
    bool _listen = false;
    bool _newData = false;
};
