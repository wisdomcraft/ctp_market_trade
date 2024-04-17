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
    QLineEdit *right_groupBox_lineEdit;     //�����ַ
    QLineEdit *right_groupBox_lineEdit2;    //���׵�ַ
    QLineEdit *right_groupBox_lineEdit3;    //BrokerID
    QLineEdit *right_groupBox_lineEdit4;    //�˺�
    QLineEdit *right_groupBox_lineEdit5;    //����
    QPushButton *right_groupbox_button;     //��¼
    QPushButton *right_groupbox_button2;    //�˳�
    
    void setupUi(QWidget *widget){
        //���ô�������
        widget->setWindowTitle( tr("CTP ����") );
        widget->resize(1000, 600);
        widget->setMinimumSize( QSize(1000, 600) );
        
        //�����ּ��������Ӳ��ֵĶ���
        QHBoxLayout *mainLayout     = new QHBoxLayout();
        mainLayout->setContentsMargins(0, 0, 0, 0);
        QVBoxLayout *leftLayout     = new QVBoxLayout();
        QVBoxLayout *rightLayout    = new QVBoxLayout();
        
        //��಼��, ѡ�
        QTabWidget * left_tabwidget = new QTabWidget();
        
        //��಼��, ѡ��еı��
        left_tabwidget_tableWidget  = new QTableWidget();
        left_tabwidget_tableWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_tabwidget_tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_tabwidget_tableWidget->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_tabwidget_tableWidget->setColumnCount(11);
        left_tabwidget_tableWidget->setHorizontalHeaderLabels
            ( QStringList() << "��Լ����"   << "��������" << "����ʱ��" << "���¼�" << "��һ��" << "��һ��"
                            << "��һ��"    << "��һ��"    << "�ɽ���"   << "��ͣ��" << "��ͣ��" );
        left_tabwidget_tableWidget->setRowCount(0);
        QTableWidget *left_tabwidget_tableWidget2= new QTableWidget();
        left_tabwidget_tableWidget2->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_tabwidget_tableWidget2->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_tabwidget_tableWidget2->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_tabwidget_tableWidget2->setColumnCount(10);
        left_tabwidget_tableWidget2->setHorizontalHeaderLabels
            ( QStringList() << "ί��ʱ��" << "��Լ����" << "����" << "��ƽ" << "����"
                            << "�۸�" << "״̬" << "ί�к�" << "������" << "BrokerID" );
        left_tabwidget_tableWidget2->setRowCount(5);
        QTableWidget *left_tabwidget_tableWidget3= new QTableWidget();
        left_tabwidget_tableWidget3->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_tabwidget_tableWidget3->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_tabwidget_tableWidget3->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_tabwidget_tableWidget3->setColumnCount(7);
        left_tabwidget_tableWidget3->setHorizontalHeaderLabels
            ( QStringList() << "�ɽ�ʱ��" << "��Լ����" << "����" << "��ƽ" << "����"
                            << "�۸�" << "ί�к�" );
        left_tabwidget_tableWidget3->setRowCount(5);
        QTableWidget *left_tabwidget_tableWidget4= new QTableWidget();
        left_tabwidget_tableWidget4->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_tabwidget_tableWidget4->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_tabwidget_tableWidget4->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_tabwidget_tableWidget4->setColumnCount(5);
        left_tabwidget_tableWidget4->setHorizontalHeaderLabels
            ( QStringList() << "��Լ����" << "�ֲ�����" << "�ֲ�����" << "�ֲֳɱ�" << "����" );
        left_tabwidget_tableWidget4->setRowCount(5);
        
        //��಼��, ѡ�, ��
        left_tabwidget->addTab( left_tabwidget_tableWidget,  tr("����") );
        left_tabwidget->addTab( left_tabwidget_tableWidget2, tr("ί��") );
        left_tabwidget->addTab( left_tabwidget_tableWidget3, tr("�ɽ�") );
        left_tabwidget->addTab( left_tabwidget_tableWidget4, tr("�ֲ�") );
        left_tabwidget->setTabPosition( QTabWidget::West );
        left_tabwidget->setTabEnabled( 0, true );
        left_tabwidget->setTabEnabled( 1, true );
        left_tabwidget->setTabEnabled( 2, true );
        left_tabwidget->setTabEnabled( 3, true );
        left_tabwidget->setTabsClosable( false );
        
        //��಼��, �м�ı��
        QTableWidget *left_mid_tableWidget = new QTableWidget();
        left_mid_tableWidget->setSelectionBehavior( QAbstractItemView::SelectRows );
        left_mid_tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );
        left_mid_tableWidget->setStyleSheet( QString(".QTableWidget{margin-left:21px;}") );
        left_mid_tableWidget->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        left_mid_tableWidget->setColumnCount(5);
        left_mid_tableWidget->setHorizontalHeaderLabels
            ( QStringList() << "�˺�" << "��Ȩ��" << "ռ�ñ�֤��" << "�����ʽ�" << "���ն�" );
        left_mid_tableWidget->setRowCount(1);
        
        //��಼��, �ײ����ı���
        left_bottom_textEdit = new QTextEdit();
        left_bottom_textEdit->setFixedHeight( 110 );
        left_bottom_textEdit->setStyleSheet( QString(".QTextEdit{margin-left:21px;}") );
        
        //�Ҳ಼��, ��Ӳ����ÿؼ�
        leftLayout->addWidget(left_tabwidget);
        leftLayout->addWidget(left_mid_tableWidget);
        leftLayout->addWidget(left_bottom_textEdit);
        leftLayout->setStretchFactor( left_tabwidget, 99);
        leftLayout->setStretchFactor( left_mid_tableWidget, 1);
        leftLayout->setStretchFactor( left_bottom_textEdit, 1);
        leftLayout->addSpacerItem( new QSpacerItem(10, 10, QSizePolicy::Expanding) );
        
        //�Ҳ಼��, ��¼
        QGroupBox *right_groupBox           = new QGroupBox( tr("��¼") );
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
        right_groupbox_button  = new QPushButton( tr("��¼") );
        right_groupbox_button2 = new QPushButton( tr("�˳�") );
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
        right_groupBox_form->addRow( tr("�����ַ:"), right_groupBox_lineEdit );
        right_groupBox_form->addRow( tr("���׵�ַ:"), right_groupBox_lineEdit2 );
        right_groupBox_form->addRow( tr("BrokerID:"), right_groupBox_lineEdit3 );
        right_groupBox_form->addRow( tr("�˺�:"), right_groupBox_lineEdit4 );
        right_groupBox_form->addRow( tr("����:"), right_groupBox_lineEdit5 );
        right_groupBox_form->addRow( right_groupbox_button_line );
        right_groupBox_form->addRow( right_groupbox_button_layout );
        right_groupBox->setLayout( right_groupBox_form );
        
        //�Ҳ಼��, �µ�
        QGroupBox *right_groupBox2          = new QGroupBox( tr("�µ�") );
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
        QRadioButton *right_groupBox2_radioButton   = new QRadioButton( tr("ƽ���") );
        QRadioButton *right_groupBox2_radioButton2  = new QRadioButton( tr("ƽ���") );
        QHBoxLayout *right_groupBox2_form_layout2   = new QHBoxLayout();
        QRadioButton *right_groupBox2_radioButton3  = new QRadioButton( tr("�޼�") );
        QLineEdit *right_groupBox2_lineEdit3        = new QLineEdit();
        QHBoxLayout *right_groupBox2_form_layout3   = new QHBoxLayout();
        QRadioButton *right_groupBox2_radioButton4  = new QRadioButton( tr("�м�") );
        QComboBox *right_groupBox2_comboBox         = new QComboBox();
        QButtonGroup *right_groupBox2_form_buttonGroup  = new QButtonGroup();
        QButtonGroup *right_groupBox2_form_buttonGroup2 = new QButtonGroup();
        right_groupBox2_form_buttonGroup    -> addButton( right_groupBox2_radioButton );
        right_groupBox2_form_buttonGroup    -> addButton( right_groupBox2_radioButton2 );
        right_groupBox2_form_buttonGroup2   -> addButton( right_groupBox2_radioButton3 );
        right_groupBox2_form_buttonGroup2   -> addButton( right_groupBox2_radioButton4 );
        right_groupBox2_comboBox    -> setMinimumWidth(70);
        right_groupBox2_comboBox    -> addItem( tr("����") );
        right_groupBox2_comboBox    -> addItem( tr("����") );
        right_groupBox2_comboBox    -> addItem( tr("ƽ��") );
        right_groupBox2_comboBox    -> addItem( tr("ƽ��") );
        right_groupBox2_form        -> addRow( tr("��Լ:"), right_groupBox2_lineEdit );
        right_groupBox2_form        -> addRow( tr("����:"), right_groupBox2_lineEdit2 );
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
        QPushButton *right_groupBox2_button = new QPushButton( tr("�µ�") );
        right_groupBox2_button  -> setCursor( QCursor(Qt::PointingHandCursor) );
        right_groupBox2_form2   -> addRow( tr("��һ��:"), right_groupBox2_label );
        right_groupBox2_form2   -> addRow( tr("���¼�:"), right_groupBox2_label2 );
        right_groupBox2_form2   -> addRow( tr("��һ��:"), right_groupBox2_label3 );
        right_groupBox2_form2   -> addRow( tr("��ͣ��:"), right_groupBox2_label4 );
        right_groupBox2_form2   -> addRow( tr("��ͣ��:"), right_groupBox2_label5 );
        right_groupBox2_form2   -> addRow( right_groupBox2_button );
        right_groupBox2_layout  -> addLayout( right_groupBox2_form );
        right_groupBox2_layout  -> addSpacerItem( new QSpacerItem(20, 20, QSizePolicy::Expanding) );
        right_groupBox2_layout  -> addLayout( right_groupBox2_form2 );
        right_groupBox2_layout  -> setStretchFactor( right_groupBox2_form, 1 );
        right_groupBox2_layout  -> setStretchFactor( right_groupBox2_form2, 1 );
        right_groupBox2         -> setLayout( right_groupBox2_layout );
        
        //�Ҳ಼��, Ƕ��
        rightLayout->addWidget(right_groupBox);
        rightLayout->addWidget(right_groupBox2);
        rightLayout->addStretch();
        
        //��������������������Ӳ���
        mainLayout->addLayout(leftLayout);
        mainLayout->addLayout(rightLayout);
        mainLayout->setStretchFactor( leftLayout, 99);
        mainLayout->setStretchFactor( rightLayout, 1);
        
        widget->setLayout(mainLayout);
    }
};

}

#endif

