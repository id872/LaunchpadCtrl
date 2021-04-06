#include "launchpadctrl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LaunchpadCtrl w;
    w.show();

    return a.exec();
}
