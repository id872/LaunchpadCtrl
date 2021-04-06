#include "launchpadctrl.h"
#include "ui_launchpadctrl.h"
#include "launchpadapi.h"

LaunchpadCtrl::LaunchpadCtrl(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::LaunchpadCtrl)
{
    _ui->setupUi(this);
    this->setFixedSize(this->size());
    _ui->animationComboBox->clear();

    if (LaunchpadAPI::GetInstance().IsInitialized() == true)
    {
        _ui->animationComboBox->addItems(LaunchpadAPI::GetInstance().GetAnimationNames());
        connect(_ui->allOnPushButton, SIGNAL(clicked()), this, SLOT(setOn()));
        connect(_ui->allOffPushButton, SIGNAL(clicked()), this, SLOT(setOff()));
        connect(_ui->animationComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(animationIndexChanged(int)));
        connect(_ui->animationSpeedSlider, SIGNAL(valueChanged(int)), this, SLOT(animatinoSpeedChanged(int)));
        connect(_ui->lpBtnSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setButton()));
        connect(_ui->redLedSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setButton()));
        connect(_ui->greenLedSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setButton()));
    }
    else
    {
        _ui->centralWidget->setEnabled(false);
        QMessageBox::information(this, "Launchpad Initialization",
                                 "Launchpad could not be initialized. Cannot control it");
        exit(-1);
    }
}

LaunchpadCtrl::~LaunchpadCtrl()
{
    LaunchpadAPI::GetInstance().Deinitialize();
    delete _ui;
}

void LaunchpadCtrl::animationIndexChanged(int i)
{
    LaunchpadAPI::GetInstance().SetAnimation((unsigned int)i);
    LaunchpadAPI::GetInstance().SetAnimationSpeed(_ui->animationSpeedSlider->value());
}

void LaunchpadCtrl::animatinoSpeedChanged(int spd)
{
    LaunchpadAPI::GetInstance().SetAnimationSpeed((unsigned int)spd);
}

void LaunchpadCtrl::setOn()
{
    LaunchpadAPI::GetInstance().SetAllButtonsOn();
}

void LaunchpadCtrl::setOff()
{
    LaunchpadAPI::GetInstance().SetAllButtonsOff();
}

void LaunchpadCtrl::setButton()
{
    int btn = _ui->lpBtnSpinBox->value();
    int green = _ui->greenLedSpinBox->value();
    int red = _ui->redLedSpinBox->value();

    LaunchpadAPI::GetInstance().SetLED(btn, ((green << 4) | red));
}
