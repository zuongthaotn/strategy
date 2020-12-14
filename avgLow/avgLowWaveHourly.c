#include "Strategy/David/vn.h"

function run()
{
    int i;

	StartDate = 2019;
	BarPeriod = 60;         // 1 per hour
	MaxLong = MaxShort = 1;
	LookBack = 40;          // 1 week ( 8 bars/per day * 5 days )
    vnDayTrading();

    vars Price = series(price());
    vars PriceLow = series(priceLow());
    var sum = 0;
    for (i = 0; i < LookBack; i++) {
        sum += PriceLow[i];
    }
    var avg_1_week =  sum / LookBack;

    var last = Price[0];
    var threshLow = avg_1_week * 1.005;
    vars threshLows = series(threshLow);

	if(crossOver(Price, threshLow)){
        enterLong(Lots, Entry, 0.08 * last, 0.05 * last);
        print(TO_LOG, "\n last %.2f,threshLow %.2f", last, threshLow);
	}
//	if(Price[0] < threshLow and Price[1] > threshLow){
//	    enterLong(Lots, Entry, 0.08 * last, 0.05 * last);
//	    print(TO_LOG, "\n last %.2f,prev_last %.2f,threshLow %.2f", last, Price[1], threshLow);
//	}

//	if(last < threshLow ){
//			enterLong(Lots, Entry, 0.08 * last, 0.05 * last);
//			print(TO_LOG, "\n last %.2f,threshLow %.2f", last, threshLow);
//
//	}

    plot("Price",Price,0,BLACK);
    plot("Price Low",PriceLow,0,YELLOW);
    plot("Thresh Low",threshLows,0,BLUE);
	set(PLOTNOW);
	set(LOGFILE); // log all trades
}
