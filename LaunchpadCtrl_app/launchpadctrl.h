#ifndef LAUNCHPADCTRL_H
#define LAUNCHPADCTRL_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>

namespace Ui {
class LaunchpadCtrl;
}

class LaunchpadCtrl : public QMainWindow
{
    Q_OBJECT

public:
    explicit LaunchpadCtrl(QWidget *parent = 0);
    ~LaunchpadCtrl();

private slots:
    void animationIndexChanged(int);
    void animatinoSpeedChanged(int);
    void setOn();
    void setOff();
    void setButton();

private:
    Ui::LaunchpadCtrl *_ui = nullptr;
};

#endif // LAUNCHPADCTRL_H
