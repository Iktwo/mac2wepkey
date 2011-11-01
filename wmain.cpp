#include "wmain.h"
#include <QDebug>

WMain::WMain(QWidget *parent) :
    QDeclarativeView(parent)
{
    m_context = rootContext();
    m_context->setContextProperty("wMain", this);

    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setSource(QUrl("qrc:/qml/main.qml"));

}
