#include <QApplication>
#include <QFrame>
#include <QRect>
#include <QDesktopWidget>
#include "html5applicationviewer.h"
#include "threading_chat.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ThreadingChat viewer;
    viewer.showExpanded();
    viewer.init();
    //move to center
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - viewer.width()) / 2;
    int y = (screenGeometry.height() - viewer.height()) / 2;
    viewer.move(x, y);

    return app.exec();
}
