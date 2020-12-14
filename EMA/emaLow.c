#include "Strategy/Magnus/fixZorro.h"

function run()
{
    int i;
    int sum = 0;

//    StartDate = 2018;
	UnstablePeriod = 0;
	BarPeriod = 1440;           // 1 da = 60 *24
	MaxLong = MaxShort = 1;
    LookBack = 10;          // 2 weeks
    fixZorro();

	var emaLow5 = EMA(series(priceLow()), 5);
	vars emaLow5_s = series(EMA(series(priceLow()), 5));
	var emaLow10 = EMA(series(priceLow()), 10);
	vars emaLow10_s = series(EMA(series(priceLow()), 10));


	if(crossUnder(emaLow10_s, emaLow5_s)){
        enterLong(Lots, Entry, 0.08 * price(), 0.05 * price());
    }
    if(crossOver(emaLow10_s, emaLow5_s)){
        exitLong();
    }

    if(!Live){
        vars Prices = series(price());
        vars priceLows = series(priceLow());
        plot("Prices",Prices,0,BLACK);
//        plot("priceLows",priceLows,0,BLUE);
        plot("emaLow5_s",emaLow5_s,0,YELLOW);
        plot("emaLow10_s",emaLow10_s,0,BLUE);
        set(PLOTNOW);
	}
	set(LOGFILE); // log all trades

}
