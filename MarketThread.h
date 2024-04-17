#ifndef _MARKETTHREAD_H_
#define _MARKETTHREAD_H_
#include <QThread>
#include "marketspi.h"

#pragma execution_character_set( "UTF-8" )


class MarketThread : public QThread
{

public:
    MarketSpi *marketSPI;

public:
    typedef struct marketStruct
    {
        char FRONT_ADDR[100];
        TThostFtdcBrokerIDType BROKER_ID;
    } marketStructAlias;
    marketStruct marketEnv;

public:
    MarketThread();
    ~MarketThread();
    void run();
};


#endif

