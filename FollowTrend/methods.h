
function method04(){
    LookBack = 10;
    vars Prices = series(price());
	vars Trends = series(Laguerre(Prices,0.05));

	vars MMI_Raws = series(MMI(Prices,LookBack));
	vars MMI_Avgs = series(SMA(MMI_Raws,LookBack));

	if(falling(MMI_Avgs)) {
		if(valley(Trends))
			enterLong();
		else if(peak(Trends))
			exitLong();
	}
	plot("Trends",Trends,0,BLUE);
	plot("MMI_Raws",MMI_Raws,NEW,GREY);
	plot("MMI_Avgs",MMI_Avgs,0,BLACK);
}

function method03(){
    vars PriceLows = series(priceLow());
	vars TrendLows = series(LowPass(PriceLows,2));

	vars MMI_Raw = series(MMI(PriceLows,5));
	vars MMI_Smooth = series(LowPass(MMI_Raw,10));
    if(crossOver(MMI_Smooth, 50)){
        enterLong(Lots, Entry, 0.08 * price(), 0.05 * price());
    }
    if(MMI_Smooth[0] > 50){
        if(falling(MMI_Smooth)){
            exitLong();
        }
    }
    plot("PriceLows",PriceLows,0,BLUE);
	plot("MMI_Raw",MMI_Raw,NEW,GREY);
	plot("MMI_Smooth",MMI_Smooth,0,BLACK);
}

function method02(){
    vars PriceLows = series(priceLow());
	vars TrendLows = series(LowPass(PriceLows,10));

	vars MMI_Raw = series(MMI(PriceLows,5));
	vars MMI_Smooth = series(LowPass(MMI_Raw,10));
    if(crossOver(MMI_Smooth, 50)){
        enterLong(Lots, Entry, 0.08 * price(), 0.05 * price());
    }
    if(crossUnder(MMI_Smooth, 50)){
        exitLong();
    }
    plot("PriceLows",PriceLows,0,BLUE);
	plot("MMI_Raw",MMI_Raw,NEW,GREY);
	plot("MMI_Smooth",MMI_Smooth,0,BLACK);
}

function method01(){
    vars PriceLows = series(priceLow());
	vars TrendLows = series(LowPass(PriceLows,10));

	vars MMI_Raw = series(MMI(PriceLows,5));
	vars MMI_Smooth = series(LowPass(MMI_Raw,10));
    if(falling(MMI_Smooth)) {
		if(valley(TrendLows))
			enterLong(Lots, Entry, 0.08 * price(), 0.05 * price());
		else if(peak(TrendLows))
			exitLong();
	}
	plot("PriceLows",PriceLows,0,BLUE);
	plot("MMI_Raw",MMI_Raw,NEW,GREY);
	plot("MMI_Smooth",MMI_Smooth,0,BLACK);

}