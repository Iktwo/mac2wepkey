#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "wmain.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WMain wMain;
    wMain.showFullScreen();

    return app.exec();
}
