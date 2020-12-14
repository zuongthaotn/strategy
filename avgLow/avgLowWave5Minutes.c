#include "Strategy/Magnus/fixZorro.h"


function run()
{
    int i;
    vnDayTrading();
    updateOpenTrades();

	StartDate = 2020;
	BarPeriod = 5;         // 1 per 5 minutes
//	MaxLong = MaxShort = 1;
	LookBack = 108;          // 2 days ( 4.5 hours/per_day * 12 bars/per_hour * 2 days )

//    vnDayTrading();
    vars Price = series(price());
    vars PriceLow = series(priceLow());
    var sum = 0;
    for (i = 0; i < LookBack; i++) {
        sum += PriceLow[i];
    }
    var avg_2_days =  sum / LookBack;

    var last = Price[0];
    var threshLow = avg_2_days * 1.001;
    vars threshLows = series(threshLow);

	if(crossOver(Price, threshLow)){
        enterLong(Lots, Entry, 0.08 * last, 0.05 * last);
        print(TO_LOG, "\n last %.2f,PriceLow %.2f, threshLow %.2f", last, PriceLow[0], threshLow);
	}

	printf("\n last %.2f,PriceLow %.2f, threshLow %.2f", last, PriceLow[0], threshLow);

//	if(Price[0] < threshLow and Price[1] > threshLow){
//	    enterLong(Lots, Entry, 0.08 * last, 0.05 * last);
//	    print(TO_LOG, "\n last %.2f,prev_last %.2f,threshLow %.2f", last, Price[1], threshLow);
//	}

//	if(last < avg_2_weeks * 1.21 ){
//			enterLong(Lots, Entry, 0.08 * last, 0.05 * last);
//			print(TO_LOG, "\n last %.2f,avg_2_weeks %.2f", last, avg_2_weeks);
//
//	}

    if(!Live){
        plot("Price",Price,0,BLACK);
        plot("Price Low",PriceLow,0,YELLOW);
        plot("Thresh Low",threshLows,0,BLUE);
        set(PLOTNOW);
	}
	set(LOGFILE); // log all trades
}
