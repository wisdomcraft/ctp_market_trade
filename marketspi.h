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
    int intRequestID = 0;       //请求ID, 对应响应里的nRequestID
    char *instrument;           //合约字符串
    int instrument_count;       //行情订阅数量
    char **instrumentID;        //行情订阅列表
    //char *ppInstrumentID[0] = {};    //行情订阅列表
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
    //错误应答
    virtual void OnRspError( CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast );
    
    //当客户端与交易后台建立通信连接时, 还未登录前, 该方法被调用
    virtual void OnFrontConnected();
    
    //当客户端与交易后台通信连接断开时，该方法被调用
    virtual void OnFrontDisconnected(int nReason);
    
    //登录请求响应，回调
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    
    //访问行情应答
    virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    
    //深度行情通知
    virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

private:
    //用户登录
    void RequestUserLogin();
    
    //订单行情数据
    void SubscribeMarketData();
    
    //错误应答的判断
    bool IsErrorResponseInformation(CThostFtdcRspInfoField *pRspInfo);

};


#endif

