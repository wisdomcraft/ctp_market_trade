#include "MarketThread.h"

#pragma execution_character_set( "UTF-8" )


//���캯��
MarketThread::MarketThread()
{
    printf( "MarketThread constructor\n" );
    marketSPI = new MarketSpi();
}


//��������
MarketThread::~MarketThread()
{
    printf( "MarketThread destruction\n" );
}

void MarketThread::run()
{
    strcpy( marketSPI->market.FRONT_ADDR,   marketEnv.FRONT_ADDR );
    strcpy( marketSPI->market.BROKER_ID,    marketEnv.BROKER_ID );
    marketSPI->init();
}

