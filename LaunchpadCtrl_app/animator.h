#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <QList>

class AnimationBase;
class MicInput;

class Animator
{
public:
    Animator();
    ~Animator();

    QList<QString> GetNames();
    void SetAnimationSpeed(unsigned int);
    void StopCurrent();
    void setNextAnimation();
    void setPrevAnimation();

    unsigned int currentAnimation() const;
    void setCurrentAnimation(unsigned int currentAnimation);

private:
    void animationThread();
    unsigned int _currentAnimation;

    bool _threadEnabled;
    QList <AnimationBase*> _animations;
    MicInput *_micInput = nullptr;
};

#endif // ANIMATOR_H
