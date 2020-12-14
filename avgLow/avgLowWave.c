#include "Strategy/Magnus/fixZorro.h"

function run()
{
    int i;

	StartDate = 2020;
	BarPeriod = 240;        // 1 day = 4.5 hours * 60 minutes/per_hour
	MaxLong = MaxShort = 1;
	LookBack = 10;          // 2 weeks = 10 days
    fixZorro();

    vars Price = series(price());
    vars PriceLow = series(priceLow());
    var sum = 0;
    for (i = 0; i < LookBack; i++) {
        sum += PriceLow[i];
    }
    var avg_2_weeks =  sum / LookBack;

    var last = Price[0];
    var threshLow = avg_2_weeks * 1.005;
    vars threshLows = series(threshLow);

	if(crossOver(Price, threshLow)){
        enterLong(Lots, Entry, 0.08 * last, 0.05 * last);
        print(TO_LOG, "\n last %.2f,avg_2_weeks %.2f", last, avg_2_weeks);
	}


    plot("Price",Price,0,BLACK);
    plot("Price Low",PriceLow,0,YELLOW);
    plot("Thresh Low",threshLows,0,BLUE);
	set(PLOTNOW);
	set(LOGFILE); // log all trades
}
