#include "Strategy/Magnus/fixZorro.h"

function run()
{
    int i;
    int sum = 0;

    StartDate = 2018;
	UnstablePeriod = 0;
	BarPeriod = 1440;           // 1 da = 60 *24
	MaxLong = MaxShort = 1;
    LookBack = 10;          // 2 weeks
    fixZorro();

	var smaLow5 = SMA(series(priceLow()), 5);
	vars smaLow5_s = series(SMA(series(priceLow()), 5));
	vars Prices = series(price());
	vars priceLows = series(priceLow());

	if(crossUnder(Prices, smaLow5_s)){
        enterLong(Lots, Entry, 0.08 * price(), 0.05 * price());
    }

    if(!Live){
        plot("Prices",Prices,0,BLACK);
        plot("priceLows",priceLows,0,BLUE);
        plot("smaLow5_s",smaLow5_s,0,YELLOW);
        set(PLOTNOW);
	}
	set(LOGFILE); // log all trades

}
