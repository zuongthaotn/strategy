#include "Strategy/Magnus/fixZorro.h"

function run()
{
    int i;
    int sum = 0;

    StartDate = 2020;
	UnstablePeriod = 0;
	BarPeriod = 1440;           // 1 da = 60 *24
	MaxLong = MaxShort = 1;
    LookBack = 10;          // 2 weeks
    fixZorro();

    vars Price = series(price());
    vars priceHigh = series(priceHigh());

    for (i = 0; i < LookBack; i++) {
        sum += priceHigh[i];
    }
    var avg_2_days =  sum / LookBack;

    var last = Price[0];
    var threshHigh = avg_2_days * 0.965;
    vars threshHighs = series(threshHigh);

	if(crossUnder(Price, threshHigh)){
	    Trail = Stop = 0.08*price();
        enterLong();
        print(TO_LOG, "\n last %.2f,priceHigh %.2f, threshHigh %.2f", last, priceHigh[0], threshHigh);
	}

    if(!Live){
        plot("Price",Price,0,BLACK);
        plot("Price High",priceHigh,0,YELLOW);
        plot("Thresh High",threshHighs,0,BLUE);
        plot("Trail",Trail,0,ORANGE);
        plot("STOP",Stop,0,RED);
        set(PLOTNOW);
	}
	set(LOGFILE); // log all trades
}
