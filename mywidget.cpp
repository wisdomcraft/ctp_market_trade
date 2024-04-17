#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <QCoreApplication>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDir>
#include <QDateTime>
#include "tinyxml2/tinyxml2.h"
#include "mywidget.h"
#include "MarketThread.h"

#pragma execution_character_set( "UTF-8" )

using namespace tinyxml2;

//构造函数
MyWidget::MyWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyWidget_ui)
{
    ui->setupUi(this);
    
    QDir dir= QDir::current();
    root    = dir.path();
    
    contract();
    readxml();
    
    marketThread= new MarketThread();
    
    connect( ui->right_groupbox_button,  &QPushButton::clicked, this, &MyWidget::ctp_login );
    connect( ui->right_groupbox_button2, &QPushButton::clicked, this, &MyWidget::ctp_logout );
    
    bool connect_result = connect( marketThread->marketSPI, SIGNAL(market_send(QString)), this, SLOT(market_receive(QString)) );
    if( connect_result != true )
        log( "error, connect() slot function failed" );
    
    bool connect_result2= connect( marketThread->marketSPI, SIGNAL(log_send(QString)), this, SLOT(log_receive(QString)) );
    if( connect_result2 != true )
        log( "error, connect() slot function failed" );
}


//析构函数
MyWidget::~MyWidget()
{
    delete ui;
}


//CTP登录
void MyWidget::ctp_login()
{
    QString address_market  = ui->right_groupBox_lineEdit->text().trimmed();
    QString address_trade   = ui->right_groupBox_lineEdit2->text().trimmed();
    QString brokerid        = ui->right_groupBox_lineEdit3->text().trimmed();
    QString account         = ui->right_groupBox_lineEdit4->text().trimmed();
    QString password        = ui->right_groupBox_lineEdit5->text().trimmed();
    
    if( address_market == "")
    {
        QMessageBox::information( this, "提示", "行情地址不能为空" );
        return ;
    }
    else if( tcpcheck(address_market) == false )
    {
        QMessageBox::information( this, "提示", "行情地址不能访问\r\n请检查是否正确, 或当前是否为交易时间\n" );
        return ;
    }
    else if( address_trade == "" )
    {
        QMessageBox::information( this, "提示", "交易地址不能为空" );
        return ;
    }
    else if( tcpcheck(address_trade) == false )
    {
        QMessageBox::information( this, "提示", "交易地址不能访问\r\n请检查是否正确, 或当前是否为交易时间\n" );
        return ;
    }
    else if( brokerid == "" )
    {
        QMessageBox::information( this, "提示", "BrokerID不能为空" );
        return ;
    }
    else if( isnumeric(brokerid) == false )
    {
        QMessageBox::information( this, "提示", "BrokerID必须为数字" );
        return ;
    }
    else if( account == "" )
    {
        QMessageBox::information( this, "提示", "账号不能为空" );
        return ;
    }
    else if( password == "" )
    {
        QMessageBox::information( this, "提示", "密码不能为空" );
        return ;
    }
    
    //写入xml
    writexml();
    
    //将QString转换为char类型
    char *char1;
    char *char2;
    char *char3;
    QByteArray byteArray1 = address_market.toLatin1();
    QByteArray byteArray2 = brokerid.toLatin1();
    QByteArray byteArray3 = account.toLatin1();
    char1 = byteArray1.data();
    char2 = byteArray2.data();
    char3 = byteArray3.data();
    
    //启动线程
    strcpy( marketThread->marketEnv.FRONT_ADDR, char1 );
    strcpy( marketThread->marketEnv.BROKER_ID,  char2 );
    marketThread->start();
    
    return ;
}


//CTP退出登录
void MyWidget::ctp_logout()
{
    printf( "ctp_logout\n" );
}


//判断字符串是否纯数字
bool MyWidget::isnumeric( const QString string )
{
    bool isNumber;
    string.toInt( &isNumber );
    return isNumber;
}


//检查TCP地址是否可连接
bool MyWidget::tcpcheck( const QString address )
{
    QStringList address_list = address.sliced(6).split(":");
    QString ip      = address_list[0];
    int port        = address_list[1].toInt();
    bool connected  = false;
    QTcpSocket tcpSocket;
    tcpSocket.connectToHost( QHostAddress(ip), port );
    if( tcpSocket.waitForConnected(1000) )
    {
        tcpSocket.close();
        connected = true;
    }
    
    return connected;
}


//char指针中的字符替换
void MyWidget::char_replace( char *str, char find, char replace )
{
    for( int i=0; str[i]!='\0'; i++ )
    {
        if( str[i] == find )
            str[i] = replace;
    }
}


//char指针中的空字符去除
void MyWidget::char_remove_space( char *str )
{
    int length = strlen( str );
    int i, j;
    for( i=0; i<length; i++ )
    {
        if( str[i] == ' ' )
        {
            for( j=i; j<length; j++ )
            {
                str[j] = str[j+1];
            }
            length--;
            i--;
        }
    }
}


//接收行情数据, 槽函数
void MyWidget::market_receive( QString tick )
{
    qDebug() << tick;
    QStringList tick_list = tick.split(",");
    
    for( int i=0; i<ui->left_tabwidget_tableWidget->rowCount(); i++)
    {
        if( ui->left_tabwidget_tableWidget->item(i,0)->text() == tick_list.at(0) )
        {
            ui->left_tabwidget_tableWidget->setItem( i, 0, new QTableWidgetItem(tick_list.at(0)) );
            ui->left_tabwidget_tableWidget->setItem( i, 1, new QTableWidgetItem(tick_list.at(1)) );
            ui->left_tabwidget_tableWidget->setItem( i, 2, new QTableWidgetItem(tick_list.at(2)) );
            ui->left_tabwidget_tableWidget->setItem( i, 3, new QTableWidgetItem(tick_list.at(3)) );
            ui->left_tabwidget_tableWidget->setItem( i, 4, new QTableWidgetItem(tick_list.at(4)) );
            ui->left_tabwidget_tableWidget->setItem( i, 5, new QTableWidgetItem(tick_list.at(5)) );
            ui->left_tabwidget_tableWidget->setItem( i, 6, new QTableWidgetItem(tick_list.at(6)) );
            ui->left_tabwidget_tableWidget->setItem( i, 7, new QTableWidgetItem(tick_list.at(7)) );
            ui->left_tabwidget_tableWidget->setItem( i, 8, new QTableWidgetItem(tick_list.at(8)) );
            ui->left_tabwidget_tableWidget->setItem( i, 9, new QTableWidgetItem(tick_list.at(9)) );
            ui->left_tabwidget_tableWidget->setItem( i, 10, new QTableWidgetItem(tick_list.at(10)) );
            return ;
        }
    }
    
    int row = ui->left_tabwidget_tableWidget->rowCount();
    ui->left_tabwidget_tableWidget->insertRow( row );
    ui->left_tabwidget_tableWidget->setItem( row, 0, new QTableWidgetItem(tick_list.at(0)) );
    ui->left_tabwidget_tableWidget->setItem( row, 1, new QTableWidgetItem(tick_list.at(1)) );
    ui->left_tabwidget_tableWidget->setItem( row, 2, new QTableWidgetItem(tick_list.at(2)) );
    ui->left_tabwidget_tableWidget->setItem( row, 3, new QTableWidgetItem(tick_list.at(3)) );
    ui->left_tabwidget_tableWidget->setItem( row, 4, new QTableWidgetItem(tick_list.at(4)) );
    ui->left_tabwidget_tableWidget->setItem( row, 5, new QTableWidgetItem(tick_list.at(5)) );
    ui->left_tabwidget_tableWidget->setItem( row, 6, new QTableWidgetItem(tick_list.at(6)) );
    ui->left_tabwidget_tableWidget->setItem( row, 7, new QTableWidgetItem(tick_list.at(7)) );
    ui->left_tabwidget_tableWidget->setItem( row, 8, new QTableWidgetItem(tick_list.at(8)) );
    ui->left_tabwidget_tableWidget->setItem( row, 9, new QTableWidgetItem(tick_list.at(9)) );
    ui->left_tabwidget_tableWidget->setItem( row, 10, new QTableWidgetItem(tick_list.at(10)) );
}


//接收log, 槽函数
void MyWidget::log_receive( QString message )
{
    log( message );
}


//写入xml
int MyWidget::writexml()
{
    QString address_market_qstring  = ui->right_groupBox_lineEdit->text().trimmed();
    QString address_trade_qstring   = ui->right_groupBox_lineEdit2->text().trimmed();
    QString brokerid_qstring        = ui->right_groupBox_lineEdit3->text().trimmed();
    QString account_qstring         = ui->right_groupBox_lineEdit4->text().trimmed();
    QString password_qstring        = ui->right_groupBox_lineEdit5->text().trimmed();
    
    const char *xmlPath     = (root + "/cache/config.xml").toStdString().c_str();
    const char *declaration = "<?xml version=\"1\" encoding=\"UTF-8\" standalone=\"no\"?>";
    XMLDocument doc;
    doc.Parse( declaration );
    
    XMLElement *xmlroot     = doc.NewElement( "ctp" );
    doc.InsertEndChild( xmlroot );
    
    XMLElement *address_market  = doc.NewElement("address_market");
    XMLText *address_market_text= doc.NewText( address_market_qstring.toStdString().c_str() );
    address_market->InsertEndChild( address_market_text );
    xmlroot->InsertEndChild( address_market );
    
    XMLElement *address_trade   = doc.NewElement("address_trade");
    XMLText *address_trade_text = doc.NewText( address_trade_qstring.toStdString().c_str() );
    address_trade->InsertEndChild( address_trade_text );
    xmlroot->InsertEndChild( address_trade );
    
    XMLElement *brokerid    = doc.NewElement("brokerid");
    XMLText *brokerid_text  = doc.NewText( brokerid_qstring.toStdString().c_str() );
    brokerid->InsertEndChild( brokerid_text );
    xmlroot->InsertEndChild( brokerid );
    
    XMLElement *account     = doc.NewElement( "account" );
    XMLText *account_text   = doc.NewText( account_qstring.toStdString().c_str() );
    account->InsertEndChild( account_text );
    xmlroot->InsertEndChild( account );
    
    XMLElement *password    = doc.NewElement("password");
    XMLText *password_text  = doc.NewText( password_qstring.toStdString().c_str() );
    password->InsertEndChild( password_text );
    xmlroot->InsertEndChild( password );
    
    int result = doc.SaveFile( xmlPath );
    if( result != 0 )
    {
        log( tr("error, config.xml doc save file failed, result: %1").arg(result) );
        return result;
    }
    log( "success, config.xml doc saved" );
    return result;
}


//读取xml
int MyWidget::readxml()
{
    const char *xmlPath = (root + "/cache/config.xml").toStdString().c_str();
    XMLDocument doc;
    int result = doc.LoadFile(xmlPath);
    if( result != 0 )
    {
        log( "error, load config.xml file failed" );
        return result;
    }
    
    XMLElement *xmlroot = doc.RootElement();
    if( xmlroot == NULL )
    {
        log( "error, root node exist in config.xml file" );
        return 0;
    }
    
    XMLElement *address_market      = xmlroot->FirstChildElement( "address_market" );
    QString address_market_qstring  = address_market->GetText();
    XMLElement *address_trade       = xmlroot->FirstChildElement( "address_trade" );
    QString address_trade_qstring   = address_trade->GetText();
    XMLElement *brokerid            = xmlroot->FirstChildElement( "brokerid" );
    QString brokerid_qstring        = brokerid->GetText();
    XMLElement *account             = xmlroot->FirstChildElement( "account" );
    QString account_qstring         = account->GetText();
    XMLElement *password            = xmlroot->FirstChildElement( "password" );
    QString password_qstring        = password->GetText();
    
    ui->right_groupBox_lineEdit->setText( address_market_qstring );
    ui->right_groupBox_lineEdit2->setText( address_trade_qstring );
    ui->right_groupBox_lineEdit3->setText( brokerid_qstring );
    ui->right_groupBox_lineEdit4->setText( account_qstring );
    ui->right_groupBox_lineEdit5->setText( password_qstring );
    
    log( "success, read config.xml file and add data into form" );
    return 0;
}


//从文件contract.log中获取合约
int MyWidget::contract()
{
    //文件路径名称
    QString file= root + "/contract.log";
    char *file2 = file.toLatin1().data();
    
    //判断文件是否存在
    FILE *fileopen;
    fileopen    = fopen( file2, "r" );
    if( fileopen == NULL )
    {
        QMessageBox::critical( this, "出错", "合约文件contract.log不存在, 程序将退出" );
        exit(0);
    }
    
    //获取内容长度
    int length = 0;
    fseek( fileopen, 0, SEEK_END );
    length = ftell( fileopen );
    rewind( fileopen );
    printf( "length: %d\n", length );
    
    //读取文件
    int ch;
    char *content = new char[ length ];
    int i = 0;
    while( (ch = fgetc(fileopen)) != EOF )
    {
        printf( "%c\n", ch );
        content[i] = ch;
        i++;
    }
    content[i] = '\0';
    
    //对换行符和空格的处理
    char_replace( content, '\n', ',' );
    char_remove_space( content );
    //*/
    printf( "%s\n", content );
    //*/
    /*
    
    //获取行数
    char line_count = 0;
    char c;
    while( (c=fgetc(fileopen)) != EOF )
    {
        if( c == '\n' )
            line_count++;
    }
    rewind( fileopen );
    
    printf( "line_count: %d\n", line_count );
    
    char line[256];
    char **contract_array = new char*[ line_count ];
    int i = 0;
    char line3[7];
    while( fgets(line, sizeof(line), fileopen) != NULL )
    {
        printf( "%zd %s\n", strlen(line), line  );
        if( strlen(line) > 1 )
        {
            printf( "strlen(line):%zd\n", strlen(line) );
            line[6] = '\0';
            strcpy( line3, line );
            printf( "i:%d, line3:%s\n", i, line3 );
            contract_array[i] = line3;
            i++;
        }
    }
    //printf( "%zd %s\n", strlen(line), line  );
    printf( "i:%d\n", i );
    printf( "contract_array[0]:%s\n", contract_array[0] );
    printf( "contract_array[1]:%s\n", contract_array[1] );
    printf( "contract_array[2]:%s\n", contract_array[2] );
    printf( "contract_array[3]:%s\n", contract_array[3] );
    */
    fclose( fileopen );
    
    return 0;
}


//日志记录
void MyWidget::log( QString message )
{
    QString datetime= QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" );
    QString logger  = tr( "【%1】%2" ).arg( datetime ).arg( message );
    ui->left_bottom_textEdit->append( logger );
}

