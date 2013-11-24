#include <QApplication>
#include <QFrame>
#include "html5applicationviewer.h"
#include "tc.h"
#include "XmppTest/xmpptest.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TChat viewer;
    //XmppTest viewer;
    viewer.setOrientation(Html5ApplicationViewer::ScreenOrientationAuto);
    viewer.resize(600, 500);
    viewer.showExpanded();

    viewer.loadFile(QLatin1String("html/index.html"));
    //viewer.loadFile(QLatin1String("html/xmpptest.html"));

    return app.exec();
}
