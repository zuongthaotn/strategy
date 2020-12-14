// Stock Breakout Trading ///////////////////
#include "Strategy/Magnus/fixZorro.h"
#include "Strategy/Magnus/Ticker.h"

function run()
{
    bool isBreakOut;

	StartDate = 2019;
	UnstablePeriod = 0;
	BarPeriod = 1440;
	MaxLong = MaxShort = 1;
	LookBack = 66;
    fixZorro();
	isBreakOut = isStockOut();
	if(isBreakOut){
        enterLong(1, 0, 0.08 * priceClose(), 0.05 * priceClose());
	}
	
	set(PLOTNOW);
	set(LOGFILE); // log all trades
}