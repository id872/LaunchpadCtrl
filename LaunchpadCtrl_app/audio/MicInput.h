#ifndef MICINPUT_H
#define MICINPUT_H
#include <QObject>

class QAudioInput;
class QAudioDeviceInfo;
class QIODevice;

class MicInput : public QObject
{
    Q_OBJECT
public:
    MicInput();
    ~MicInput();
    void initializeAudio(const QAudioDeviceInfo &deviceInfo);
    float getCurrentSoundLevel() { return _soundLevel; }

private slots:
    void inputDataReceived();

private:
    void startCapture();
    void stopCapture();

    QAudioInput *_audioInput = nullptr;
    QIODevice *_audioInputDevice = nullptr;

    float _soundLevel = 0;
};

#endif // MICINPUT_H
