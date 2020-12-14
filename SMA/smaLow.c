#include "Strategy/Magnus/fixZorro.h"

function run()
{
    int i;
    int sum = 0;

    StartDate = 2018;
	UnstablePeriod = 0;
	BarPeriod = 1440;           // 1 day = 60 *24
	MaxLong = MaxShort = 1;
    LookBack = 10;          // 2 weeks
    fixZorro();

	var smaLow5 = SMA(series(priceLow()), 5);
	vars smaLow5_s = series(SMA(series(priceLow()), 5));
	var smaLow10 = SMA(series(priceLow()), 10);
	vars smaLow10_s = series(SMA(series(priceLow()), 10));


	if(crossUnder(smaLow10_s, smaLow5_s)){
        enterLong(Lots, Entry, 0.08 * price(), 0.05 * price());
    }
    if(crossOver(smaLow10_s, smaLow5_s)){
        exitLong();
    }

    if(!Live){
        vars Prices = series(price());
        vars priceLows = series(priceLow());
        plot("Prices",Prices,0,BLACK);
//        plot("priceLows",priceLows,0,BLUE);
        plot("smaLow5_s",smaLow5_s,0,YELLOW);
        plot("smaLow10_s",smaLow10_s,0,BLUE);
        set(PLOTNOW);
	}
	set(LOGFILE); // log all trades

}
