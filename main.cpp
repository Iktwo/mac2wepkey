#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "wmain.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("Iktwo Corp.");
    QCoreApplication::setOrganizationDomain("iktwo.com");
    QCoreApplication::setApplicationName("mac2wepkey");
    QCoreApplication::setApplicationVersion("2.0.3");

    WMain wMain;

    return app.exec();
}
