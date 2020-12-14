function run()
{
    MaxLong = MaxShort = 1;

	StartDate = 2019;
	BarPeriod = 1440;

    vars Price = series(priceClose());
    vars ema5  = series(EMA(Price, 5));
    vars ema10 = series(EMA(Price, 10));

    if (priceClose() > ema5[0] and crossOver(ema5, ema10)) {
        enterLong();
    }
    if (crossUnder(ema5, ema10)) {
        exitLong();
    }

	set(PLOTNOW);
	set(LOGFILE);
}
