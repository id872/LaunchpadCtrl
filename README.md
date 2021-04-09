# LaunchpadCtrl

Relaxing animations and sound visualization on the Launchpad S.

![Launchpad animation - random](launchpad_animation.gif)

One of the animations implemented is mic sound visualization.
Sound is captured from default microphone and converted to sound level value.
LED rows are enabled according to the sound level. YouTube videos below.

[![Launchpad sound visualization](https://img.youtube.com/vi/xT6X5TINXxA/0.jpg)](https://www.youtube.com/watch?v=xT6X5TINXxA)

Animations:

[![Launchpad animations](https://img.youtube.com/vi/Ujcrv2wp1KI/0.jpg)](https://www.youtube.com/watch?v=Ujcrv2wp1KI)

# Dependencies

* Device: Novation Launchpad S
* OS: Linux (snd_seq_midi kernel module)
* Libraries: Qt Multimedia, ALSA

# Build
Make file generate
```shell
qmake
```
Build executable
```shell
make -j4
```

# Application view

![LaunchpadCtrl application view](application.png)
