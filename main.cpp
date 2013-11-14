#include <QApplication>
#include <QFrame>
#include "html5applicationviewer.h"
#include "tc.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TChat viewer;
    viewer.setOrientation(Html5ApplicationViewer::ScreenOrientationAuto);
    viewer.resize(600, 500);
    viewer.showExpanded();

    viewer.loadFile(QLatin1String("html/index.html"));

    return app.exec();
}
