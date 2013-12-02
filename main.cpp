#include <QApplication>
#include <QFrame>
#include "html5applicationviewer.h"
#include "threading_chat.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ThreadingChat viewer;
    viewer.showExpanded();
    viewer.init();

    return app.exec();
}
