#ifndef _MYWIDGET_H_
#define _MYWIDGET_H_
#include <QWidget>
#include "mywidget_ui.h"
#include "MarketThread.h"

#pragma execution_character_set( "UTF-8" )

namespace Ui { class MyWidget_ui; }

class MyWidget : public QWidget{
    Q_OBJECT

private:
    Ui::MyWidget_ui     *ui;
    MarketThread        *marketThread;
    QString             root;
public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void ctp_login();
    void ctp_logout();
    bool isnumeric( const QString );
    bool tcpcheck( const QString );
    void char_replace( char *str, char find, char replace );
    void char_remove_space( char *str );
private:
    int writexml();
    int readxml();
    int contract();
    void log( QString );
private slots:
    void market_receive( QString );
    void log_receive( QString );
};

#endif

