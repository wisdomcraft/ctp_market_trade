#include <iostream>
#include <QApplication>
#include "mywidget.h"

#pragma execution_character_set( "UTF-8" )

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget myWidget;
    myWidget.show();
    
    return app.exec();
}

