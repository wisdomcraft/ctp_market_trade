#include <stdio.h>
#include <iostream>
#include <string>
#include <QDebug>
#include "marketspi.h"

//#pragma execution_character_set( "UTF-8" )

char *ppInstrumentID[]  = { (char *)"cu2405", (char *)"au2406", (char *)"ag2406"};  //行情订阅列表


//构造函数
MarketSpi::MarketSpi( QObject *parent )
{
    instrument_count = 3;
    instrument = (char *)"cu2405,au2406,ag2406";    //const char[21]
    static const int length2 = instrument_count;
    static const int length = 3;
    //char *instrumentID2[ length2 ];
    //char **instrumentID = new char*[ instrument_count ];
    //char **instrumentID;
    instrumentID = new char*[ instrument_count ];
    instrumentID[0] = (char *)"cu2405";
    instrumentID[1] = (char *)"au2406";
    instrumentID[2] = (char *)"ag2406";
    
    //char *temp = strtok( instrument, "," );
    
    //ppInstrumentID[]    = { (char *)"cu2405", (char *)"au2406", (char *)"ag2406"};
    //instrument
}


//析构函数
MarketSpi::~MarketSpi()
{
    delete[] instrumentID;
    instrumentID = NULL;
}


//初始化
void MarketSpi::init()
{
    QString tick = "info, start login CTP market sever";
    emit log_send( tick );
    //return ;
    marketAPI = CThostFtdcMdApi::CreateFtdcMdApi();
    marketAPI->RegisterSpi( this );
    marketAPI->RegisterFront( market.FRONT_ADDR );
    marketAPI->Init();
    marketAPI->Join();
    //marketAPI->Release();
}


//response回复出错
void MarketSpi::OnRspError( CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast ){
    emit log_send( tr("error, OnRspError, ErrorID: %1").arg( pRspInfo->ErrorID ) );
}


/*
* 判断是否已连接
* 当客户端与交易后台建立通信连接时, 还未登录前, 该方法被调用
*/
void MarketSpi::OnFrontConnected(){
    emit log_send( "info, market CTP server connected, OnFrontConnected" );
    RequestUserLogin();
}


//连接断开
void MarketSpi::OnFrontDisconnected(int nReason){
    emit log_send( "info, market CTP server disconnect, OnFrontDisconnected" );
}


//用户登录
void MarketSpi::RequestUserLogin(){
    CThostFtdcReqUserLoginField user;
    memset(&user, 0, sizeof(user));
    strcpy(user.BrokerID,   market.BROKER_ID);
    strcpy(user.UserID,     "");
    strcpy(user.Password,   "");
    int result = marketAPI->ReqUserLogin(&user, ++intRequestID);
    if(result == 0){
        emit log_send( "info, login success, RequestUserLogin" );
    }else{
        emit log_send( "error, login failed, RequestUserLogin" );
    }
}


//用户登录，回调
void MarketSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    emit log_send( "info, callback after login success, OnRspUserLogin" );
    if ( bIsLast && !IsErrorResponseInformation(pRspInfo) ){
        QString tradingDay = marketAPI->GetTradingDay();
        emit log_send( tr("OnRspUserLogin, 获取当前交易日, %1").arg(tradingDay) );
        SubscribeMarketData();
    }
}


//订阅行情数据
void MarketSpi::SubscribeMarketData(){
    //int intResult = marketAPI->SubscribeMarketData( ppInstrumentID, instrument_count );
    int intResult = marketAPI->SubscribeMarketData( instrumentID, instrument_count );
    QString result;
    if(intResult == 0){
        result = "success";
    }else{
        result = "failed";
    }
    emit log_send( tr("info, send result in SubscribeMarketData, %1").arg(result) );
}


//订阅行情应答
void MarketSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    QString instrumentID = pSpecificInstrument->InstrumentID;
    emit log_send( tr("info, OnRspSubMarketData, 合约代码: %1").arg(instrumentID) );
}


//深度行情通知
void MarketSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
    QString tradingDay      = pDepthMarketData->TradingDay;                             //交易日
    QString updatetime      = pDepthMarketData->UpdateTime;                             //更新时间
    QString contract        = pDepthMarketData->InstrumentID;                           //合约代码
    QString lastprice       = QString::number( pDepthMarketData->LastPrice );           //新新价
    QString buyprice        = QString::number( pDepthMarketData->BidPrice1 );           //买价
    QString buyvolume       = QString::number( pDepthMarketData->BidVolume1 );          //买量
    QString sellprice       = QString::number( pDepthMarketData->AskPrice1 );           //卖价
    QString sellvolume      = QString::number( pDepthMarketData->AskVolume1 );          //卖量
    QString volume          = QString::number( pDepthMarketData->Volume );              //成交量
    QString upperlimit      = QString::number( pDepthMarketData->UpperLimitPrice );     //涨停
    QString lowerlimit      = QString::number( pDepthMarketData->LowerLimitPrice );     //跌停
    
    QString tick = tr("%1,%2,%3,%4,%5,%6,%7,%8,%9,%10,%11").arg( contract )
                        .arg( tradingDay )
                        .arg( updatetime )
                        .arg( lastprice )
                        .arg( buyprice )
                        .arg( buyvolume )
                        .arg( sellprice )
                        .arg( sellvolume )
                        .arg( volume )
                        .arg( upperlimit )
                        .arg( lowerlimit );
    emit market_send( tick );
}


//回调的错误信息
bool MarketSpi::IsErrorResponseInformation( CThostFtdcRspInfoField *pRspInfo )
{
    bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
    if (bResult){
        return bResult;
    }
    return bResult;
}

