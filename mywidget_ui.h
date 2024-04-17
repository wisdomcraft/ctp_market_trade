#ifndef _MYWIDGET_UI_H_
#define _MYWIDGET_UI_H_
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QTabWidget>
#include <QFrame>
#include <QTableWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QButtonGroup>
#include <QRadioButton>
#include <QSpacerItem>
#include <QComboBox>

#pragma execution_character_set( "UTF-8" )

namespace Ui
{

class MyWidget_ui : public QWidget{

public:
    QTableWidget *left_tabwidget_tableWidget;
    QTextEdit *left_bottom_textEdit;
    QLineEdit *right_groupBox_lineEdit;     //行情地址
    QLineEdit *right_groupBox_lineEdit2;    //交易地址
    QLineEdit *right_groupBox_lineEdit3;    //BrokerID
    QLineEdit *right_groupBox_lineEdit4;    //账号
    QLineEdit *right_groupBox_lineEdit5;    //密码
    QPushButton *right_groupbox_button;     //登录
    QPushButton *right_groupbox_button2;    //退出
    
    void setupUi(QWidget *widget){
        //设置窗口属性
        widget->setWindowTitle( tr("CTP 测试") );
        widget->resize(1000, 600);
        widget->setMinimumSize( QSize(1000, 600) );
        
        //主布局及其左右子布局的定义
        QHBoxLayout *mainLayout     = new QHBoxLayout();
        mainLayout->setContentsMargins(0, 0, 0, 0);
        QVBoxLayout *leftLayout     = new QVBoxLayout();
        QVBoxLayout *rightLayout    = new QVBoxLayout();
        
        //左侧布局, 选项卡
        QTabWidget * left_tabwidget = new QTabWidget();
        
        //左侧布局, 选项卡中的表格
        left_tabwidget_tableWidget  = new QTableWidget();
        left_tabwidget_tableWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_tabwidget_tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_tabwidget_tableWidget->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_tabwidget_tableWidget->setColumnCount(11);
        left_tabwidget_tableWidget->setHorizontalHeaderLabels
            ( QStringList() << "合约代码"   << "交易日期" << "更新时间" << "最新价" << "买一价" << "买一量"
                            << "卖一价"    << "卖一量"    << "成交量"   << "涨停价" << "跌停价" );
        left_tabwidget_tableWidget->setRowCount(0);
        QTableWidget *left_tabwidget_tableWidget2= new QTableWidget();
        left_tabwidget_tableWidget2->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_tabwidget_tableWidget2->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_tabwidget_tableWidget2->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_tabwidget_tableWidget2->setColumnCount(10);
        left_tabwidget_tableWidget2->setHorizontalHeaderLabels
            ( QStringList() << "委托时间" << "合约代码" << "买卖" << "开平" << "数量"
                            << "价格" << "状态" << "委托号" << "交易所" << "BrokerID" );
        left_tabwidget_tableWidget2->setRowCount(5);
        QTableWidget *left_tabwidget_tableWidget3= new QTableWidget();
        left_tabwidget_tableWidget3->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_tabwidget_tableWidget3->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_tabwidget_tableWidget3->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_tabwidget_tableWidget3->setColumnCount(7);
        left_tabwidget_tableWidget3->setHorizontalHeaderLabels
            ( QStringList() << "成交时间" << "合约代码" << "买卖" << "开平" << "数量"
                            << "价格" << "委托号" );
        left_tabwidget_tableWidget3->setRowCount(5);
        QTableWidget *left_tabwidget_tableWidget4= new QTableWidget();
        left_tabwidget_tableWidget4->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_tabwidget_tableWidget4->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_tabwidget_tableWidget4->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_tabwidget_tableWidget4->setColumnCount(5);
        left_tabwidget_tableWidget4->setHorizontalHeaderLabels
            ( QStringList() << "合约代码" << "持仓类型" << "持仓数量" << "持仓成本" << "数量" );
        left_tabwidget_tableWidget4->setRowCount(5);
        
        //左侧布局, 选项卡, 续
        left_tabwidget->addTab( left_tabwidget_tableWidget,  tr("行情") );
        left_tabwidget->addTab( left_tabwidget_tableWidget2, tr("委托") );
        left_tabwidget->addTab( left_tabwidget_tableWidget3, tr("成交") );
        left_tabwidget->addTab( left_tabwidget_tableWidget4, tr("持仓") );
        left_tabwidget->setTabPosition( QTabWidget::West );
        left_tabwidget->setTabEnabled( 0, true );
        left_tabwidget->setTabEnabled( 1, true );
        left_tabwidget->setTabEnabled( 2, true );
        left_tabwidget->setTabEnabled( 3, true );
        left_tabwidget->setTabsClosable( false );
        
        //左侧布局, 中间的表格
        QTableWidget *left_mid_tableWidget = new QTableWidget();
        left_mid_tableWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_mid_tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_mid_tableWidget->setStyleSheet( QString(".QTableWidget{margin-left:21px;}") );
        left_mid_tableWidget->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_mid_tableWidget->setColumnCount(5);
        left_mid_tableWidget->setHorizontalHeaderLabels
            ( QStringList() << "账号" << "总权益" << "占用保证金" << "可用资金" << "风险度" );
        left_mid_tableWidget->setRowCount(1);
        
        //左侧布局, 底部的文本域
        left_bottom_textEdit = new QTextEdit();
        left_bottom_textEdit->setFixedHeight( 110 );
        left_bottom_textEdit->setStyleSheet( QString(".QTextEdit{margin-left:21px;}") );
        
        //右侧布局, 添加并设置控件
        leftLayout->addWidget(left_tabwidget);
        leftLayout->addWidget(left_mid_tableWidget);
        leftLayout->addWidget(left_bottom_textEdit);
        leftLayout->setStretchFactor( left_tabwidget, 99);
        leftLayout->setStretchFactor( left_mid_tableWidget, 1);
        leftLayout->setStretchFactor( left_bottom_textEdit, 1);
        leftLayout->addSpacerItem( new QSpacerItem(10, 10, QSizePolicy::Expanding) );
        
        //右侧布局, 登录
        QGroupBox *right_groupBox           = new QGroupBox( tr("登录") );
        right_groupBox->setStyleSheet( QString(".QGroupBox{margin-top:15px; \
                                                    margin-right:5px; \
                                                    padding-top:20px; \
                                                    padding-bottom:10px; \
                                                    width:280px;} \
                                                .QGroupBox::title{subcontrol-origin: margin; \
                                                    subcontrol-position: top left; \
                                                    margin-left: 0px; \
                                                    left:10px; \
                                                    padding: 8px 1px 0 1px;}") );
        QFormLayout *right_groupBox_form    = new QFormLayout();
        right_groupBox_form->setSpacing(10);
        right_groupBox_form->setLabelAlignment( Qt::AlignRight );
        right_groupBox_lineEdit  = new QLineEdit();
        right_groupBox_lineEdit2 = new QLineEdit();
        right_groupBox_lineEdit3 = new QLineEdit();
        right_groupBox_lineEdit4 = new QLineEdit();
        right_groupBox_lineEdit5 = new QLineEdit();
        right_groupBox_lineEdit5->setEchoMode( QLineEdit::Password );
        right_groupbox_button  = new QPushButton( tr("登录") );
        right_groupbox_button2 = new QPushButton( tr("退出") );
        right_groupbox_button->setCursor( QCursor(Qt::PointingHandCursor) );
        right_groupbox_button2->setCursor( QCursor(Qt::PointingHandCursor) );
        QSpacerItem *spacer                 = new QSpacerItem(20, 20, QSizePolicy::Expanding);
        QHBoxLayout *right_groupbox_button_layout = new QHBoxLayout();
        QFrame *right_groupbox_button_line  = new QFrame();
        right_groupbox_button_line->setFrameShape( QFrame::HLine );
        right_groupbox_button_line->setStyleSheet( QString(".QFrame{background-color:rgb(250,250,250);color:#c5c5c5;}") );
        right_groupbox_button_layout->setSizeConstraint( QLayout::SetFixedSize );
        right_groupbox_button_layout->addSpacerItem( spacer );
        right_groupbox_button_layout->addWidget( right_groupbox_button );
        right_groupbox_button_layout->addSpacerItem( spacer );
        right_groupbox_button_layout->addWidget( right_groupbox_button2 );
        right_groupbox_button_layout->addSpacerItem( spacer );
        right_groupBox_form->addRow( tr("行情地址:"), right_groupBox_lineEdit );
        right_groupBox_form->addRow( tr("交易地址:"), right_groupBox_lineEdit2 );
        right_groupBox_form->addRow( tr("BrokerID:"), right_groupBox_lineEdit3 );
        right_groupBox_form->addRow( tr("账号:"), right_groupBox_lineEdit4 );
        right_groupBox_form->addRow( tr("密码:"), right_groupBox_lineEdit5 );
        right_groupBox_form->addRow( right_groupbox_button_line );
        right_groupBox_form->addRow( right_groupbox_button_layout );
        right_groupBox->setLayout( right_groupBox_form );
        
        //右侧布局, 下单
        QGroupBox *right_groupBox2          = new QGroupBox( tr("下单") );
        right_groupBox2->setStyleSheet( QString(".QGroupBox{margin-top:10px; \
                                                        margin-right:5px; \
                                                        padding-top:20px; \
                                                        padding-bottom:10px;\
                                                        border: 1px solid #dddddd;} \
                                                .QGroupBox::title{subcontrol-origin: margin; \
                                                        subcontrol-position: top left; \
                                                        margin-left: 0px; \
                                                        left:10px; \
                                                        padding: 2px 1px 0 1px;}") );
        QHBoxLayout *right_groupBox2_layout = new QHBoxLayout();
        QFormLayout *right_groupBox2_form   = new QFormLayout();
        QFormLayout *right_groupBox2_form2  = new QFormLayout();
        right_groupBox2_form    -> setSpacing(11);
        right_groupBox2_form2   -> setSpacing(10);
        QLineEdit *right_groupBox2_lineEdit = new QLineEdit();
        QLineEdit *right_groupBox2_lineEdit2= new QLineEdit();
        QHBoxLayout *right_groupBox2_form_layout    = new QHBoxLayout();
        QRadioButton *right_groupBox2_radioButton   = new QRadioButton( tr("平昨仓") );
        QRadioButton *right_groupBox2_radioButton2  = new QRadioButton( tr("平今仓") );
        QHBoxLayout *right_groupBox2_form_layout2   = new QHBoxLayout();
        QRadioButton *right_groupBox2_radioButton3  = new QRadioButton( tr("限价") );
        QLineEdit *right_groupBox2_lineEdit3        = new QLineEdit();
        QHBoxLayout *right_groupBox2_form_layout3   = new QHBoxLayout();
        QRadioButton *right_groupBox2_radioButton4  = new QRadioButton( tr("市价") );
        QComboBox *right_groupBox2_comboBox         = new QComboBox();
        QButtonGroup *right_groupBox2_form_buttonGroup  = new QButtonGroup();
        QButtonGroup *right_groupBox2_form_buttonGroup2 = new QButtonGroup();
        right_groupBox2_form_buttonGroup    -> addButton( right_groupBox2_radioButton );
        right_groupBox2_form_buttonGroup    -> addButton( right_groupBox2_radioButton2 );
        right_groupBox2_form_buttonGroup2   -> addButton( right_groupBox2_radioButton3 );
        right_groupBox2_form_buttonGroup2   -> addButton( right_groupBox2_radioButton4 );
        right_groupBox2_comboBox    -> setMinimumWidth(70);
        right_groupBox2_comboBox    -> addItem( tr("开多") );
        right_groupBox2_comboBox    -> addItem( tr("开空") );
        right_groupBox2_comboBox    -> addItem( tr("平多") );
        right_groupBox2_comboBox    -> addItem( tr("平空") );
        right_groupBox2_form        -> addRow( tr("合约:"), right_groupBox2_lineEdit );
        right_groupBox2_form        -> addRow( tr("数量:"), right_groupBox2_lineEdit2 );
        right_groupBox2_form_layout -> addWidget( right_groupBox2_radioButton );
        right_groupBox2_form_layout -> addWidget( right_groupBox2_radioButton2 );
        right_groupBox2_form        -> addRow( right_groupBox2_form_layout );
        right_groupBox2_form_layout2-> addWidget( right_groupBox2_radioButton3 );
        right_groupBox2_form_layout2-> addWidget( right_groupBox2_lineEdit3 );
        right_groupBox2_form        -> addRow( right_groupBox2_form_layout2 );
        right_groupBox2_form_layout3-> addWidget( right_groupBox2_radioButton4 );
        right_groupBox2_form_layout3-> addWidget( right_groupBox2_comboBox );
        right_groupBox2_form        -> addRow( right_groupBox2_form_layout3 );
        QLabel *right_groupBox2_label   = new QLabel( tr("-") );
        QLabel *right_groupBox2_label2  = new QLabel( tr("-") );
        QLabel *right_groupBox2_label3  = new QLabel( tr("-") );
        QLabel *right_groupBox2_label4  = new QLabel( tr("-") );
        QLabel *right_groupBox2_label5  = new QLabel( tr("-") );
        QPushButton *right_groupBox2_button = new QPushButton( tr("下单") );
        right_groupBox2_button  -> setCursor( QCursor(Qt::PointingHandCursor) );
        right_groupBox2_form2   -> addRow( tr("卖一价:"), right_groupBox2_label );
        right_groupBox2_form2   -> addRow( tr("最新价:"), right_groupBox2_label2 );
        right_groupBox2_form2   -> addRow( tr("买一价:"), right_groupBox2_label3 );
        right_groupBox2_form2   -> addRow( tr("涨停价:"), right_groupBox2_label4 );
        right_groupBox2_form2   -> addRow( tr("跌停价:"), right_groupBox2_label5 );
        right_groupBox2_form2   -> addRow( right_groupBox2_button );
        right_groupBox2_layout  -> addLayout( right_groupBox2_form );
        right_groupBox2_layout  -> addSpacerItem( new QSpacerItem(20, 20, QSizePolicy::Expanding) );
        right_groupBox2_layout  -> addLayout( right_groupBox2_form2 );
        right_groupBox2_layout  -> setStretchFactor( right_groupBox2_form, 1 );
        right_groupBox2_layout  -> setStretchFactor( right_groupBox2_form2, 1 );
        right_groupBox2         -> setLayout( right_groupBox2_layout );
        
        //右侧布局, 嵌套
        rightLayout->addWidget(right_groupBox);
        rightLayout->addWidget(right_groupBox2);
        rightLayout->addStretch();
        
        //主布局中添加左、右两个子布局
        mainLayout->addLayout(leftLayout);
        mainLayout->addLayout(rightLayout);
        mainLayout->setStretchFactor( leftLayout, 99);
        mainLayout->setStretchFactor( rightLayout, 1);
        
        widget->setLayout(mainLayout);
    }
};

}

#endif

