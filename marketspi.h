#ifndef _MARKETSPI_H_
#define _MARKETSPI_H_
#include <QObject>
#include "ctp/ThostFtdcMdApi.h"

#pragma execution_character_set( "UTF-8" )


class MarketSpi : public QObject, public CThostFtdcMdSpi
{
    Q_OBJECT

public:
    typedef struct marketStruct
    {
        char FRONT_ADDR[100];
        TThostFtdcBrokerIDType BROKER_ID;
    } marketStructAlias;
    marketStruct    market;

private:
    int intRequestID = 0;       //����ID, ��Ӧ��Ӧ���nRequestID
    char *instrument;           //��Լ�ַ���
    int instrument_count;       //���鶩������
    char **instrumentID;        //���鶩���б�
    //char *ppInstrumentID[0] = {};    //���鶩���б�
    //char *ppInstrumentID2[0];

public:
    CThostFtdcMdApi *marketAPI;

public:
    MarketSpi( QObject *parent=nullptr );
    ~MarketSpi();
    void init();

signals:
    void log_send( QString );
    void market_send( QString );

public:
    //����Ӧ��
    virtual void OnRspError( CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast );
    
    //���ͻ����뽻�׺�̨����ͨ������ʱ, ��δ��¼ǰ, �÷���������
    virtual void OnFrontConnected();
    
    //���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷���������
    virtual void OnFrontDisconnected(int nReason);
    
    //��¼������Ӧ���ص�
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    
    //��������Ӧ��
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    
    //�������֪ͨ
    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

private:
    //�û���¼
    void RequestUserLogin();
    
    //������������
    void SubscribeMarketData();
    
    //����Ӧ����ж�
    bool IsErrorResponseInformation(CThostFtdcRspInfoField *pRspInfo);

};


#endif

