#include "Strategy/Magnus/fixZorro.h"


function run()
{
    int i;
    int sum = 0;

    StartDate = 2019;
	UnstablePeriod = 0;
	BarPeriod = 5;
	MaxLong = MaxShort = 1;
    LookBack = 108;          // 2 days ( 4.5 hours/per_day * 12 bars/per_hour * 2 days )
    fixZorro();

    vars Price = series(price());
    vars priceHigh = series(priceHigh());

    for (i = 0; i < LookBack; i++) {
        sum += priceHigh[i];
    }
    var avg_2_days =  sum / LookBack;

    var last = Price[0];
    var threshHigh = avg_2_days * 0.65;
    vars threshHighs = series(threshHigh);

	if(crossOver(Price, threshHigh)){
        enterLong(Lots, Entry, 0.08 * last, 0.05 * last);
        print(TO_LOG, "\n last %.2f,priceHigh %.2f, threshHigh %.2f", last, priceHigh[0], threshHigh);
	}

	printf("\n last %.2f,priceHigh %.2f, threshHigh %.2f", last, priceHigh[0], threshHigh);

    if(!Live){
        plot("Price",Price,0,BLACK);
        plot("Price High",priceHigh,0,YELLOW);
        plot("Thresh High",threshHighs,0,BLUE);
        set(PLOTNOW);
	}
	set(LOGFILE); // log all trades
}
