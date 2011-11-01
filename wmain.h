#ifndef WMAIN_H
#define WMAIN_H

#include <QDeclarativeView>
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QDeclarativeContext>

class WMain : public QDeclarativeView
{
    Q_OBJECT
public:
    explicit WMain(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    QDeclarativeContext *m_context;
    
};

#endif // WMAIN_H
