######################################################################
# Automatically generated by qmake (3.1) Thu Feb 18 18:07:07 2021
######################################################################

TEMPLATE = app
TARGET = LaunchpadCtrl
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += multimedia widgets

# Input
HEADERS += animator.h \
           launchpadapi.h \
           launchpadctrl.h \
           midi_device/mididevice.h \
           midi_device/launchpadS.h \
           midi_device/RtMidi.h \
           audio/MicInput.h \
           symbolgenerator.h \
           animations/animationbase.h \
           animations/animationcandles.h \
           animations/animationchristmas.h \
           animations/animationheart.h \
           animations/animationrandom.h \
           animations/animationrandomii.h \
           animations/animationsnake.h \
           animations/animationstandby.h \
           animations/animationsound.h \
           animations/animationwave.h
FORMS += launchpadctrl.ui
SOURCES += animator.cpp \
           launchpadapi.cpp \
           launchpadctrl.cpp \
           midi_device/mididevice.cpp \
           midi_device/launchpadS.cpp \
           midi_device/RtMidi.cpp \
           main.cpp \
           audio/MicInput.cpp \
           symbolgenerator.cpp \
           animations/animationbase.cpp \
           animations/animationcandles.cpp \
           animations/animationchristmas.cpp \
           animations/animationheart.cpp \
           animations/animationrandom.cpp \
           animations/animationrandomii.cpp \
           animations/animationsnake.cpp \
           animations/animationstandby.cpp \
           animations/animationsound.cpp \
           animations/animationwave.cpp

DEFINES  += __LINUX_ALSA__

LIBS     += -lasound