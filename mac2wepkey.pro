CONFIG += qdeclarative-boostable

SOURCES += main.cpp \
    wmain.cpp \
    networkdetails.cpp

QT += dbus

include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qml/TittleBar.qml \
    qml/MainPage.qml \
    qml/main.qml \
    qml/AboutDialog.qml \
    qml/NetworkList.qml \
    qml/WritePage.qml

RESOURCES += \
    resources.qrc

HEADERS += \
    wmain.h \
    networkdetails.h









