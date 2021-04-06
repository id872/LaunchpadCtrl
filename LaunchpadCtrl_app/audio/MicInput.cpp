#include "MicInput.h"

#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioInput>

MicInput::MicInput()
{
    initializeAudio(QAudioDeviceInfo::defaultInputDevice());
    startCapture();
}

MicInput::~MicInput()
{
    stopCapture();
}

void MicInput::initializeAudio(const QAudioDeviceInfo &deviceInfo)
{
    if (_audioInput != nullptr)
        return;

    QAudioFormat format;
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setSampleType(QAudioFormat::UnSignedInt);
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setCodec("audio/pcm");

    if (!deviceInfo.isFormatSupported(format)) {
        format = deviceInfo.nearestFormat(format);
    }

    _audioInput = new QAudioInput(deviceInfo, format);
}

void MicInput::startCapture()
{
    if (_audioInput != nullptr)
    {
        _audioInputDevice = _audioInput->start();
        connect(_audioInputDevice, SIGNAL(readyRead()), SLOT(inputDataReceived()));
    }
}

void MicInput::stopCapture()
{
    if (_audioInputDevice != nullptr)
    {
        _audioInputDevice->disconnect();
        _audioInputDevice->close();
        _audioInput->stop();
    }
}

void MicInput::inputDataReceived()
{
    QByteArray data;
    const qint64 numSamples = _audioInput->bytesReady();

    if (numSamples > 0)
    {
        data.resize(numSamples);
        _audioInputDevice->read(data.data(), numSamples);

        quint32 maxValue = 0;
        const unsigned char *ptr = reinterpret_cast<const unsigned char *>(data.data());

        for (int i = 0; i < numSamples; ++i) {
            quint32 value = 0;
            value = *reinterpret_cast<const quint8*>(ptr);

            maxValue = qMax(value, maxValue);
            ptr += 1;
        }

        maxValue = qMin(maxValue, (quint32)255);
        _soundLevel = qreal(maxValue) / 255;
    }
}
