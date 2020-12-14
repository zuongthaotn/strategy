// Trend Trading ///////////////////
#include <profile.c>

function run()
{
	StartDate = 2019;
	BarPeriod = 480;
	vars Price = series(price());
	var sma10 = SMA(series(priceClose()), 10);
	var sma2 = SMA(series(priceClose()), 2);
	var sma20 = SMA(series(priceClose()), 20);

	vars sma10_s = series(SMA(series(priceClose()), 10));
	vars sma2_s = series(SMA(series(priceClose()), 2));
	vars sma20_s = series(SMA(series(priceClose()), 20));

	Stop = Trail = 4*ATR(5);

    MaxLong = MaxShort = 1;

    if(crossUnder(sma20_s, sma2_s)){
        enterLong();
    }
    if(crossOver(sma20_s, sma2_s)){
        exitLong();
    }


//    PlotScale = 8;
//	plot("SMA20",sma20,0,BLUE);
////	plot("SMA10",sma10,0,YELLOW);
//	plot("SMA2",sma2,0,YELLOW);

	set(PLOTNOW);
}