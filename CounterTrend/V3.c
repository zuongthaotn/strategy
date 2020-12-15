#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "BCG", "CMX", "DLG", "DRH", "HAG", "LDG", "SCR", "SZC", "TDC", "TNI", "TSC", "TTB", "VHC"
#define ASSETS      RPM 
#define N           13
var getThreshHold(string ticker);

function run()
{
	BarPeriod = 3;
	MaxLong = MaxShort = 1;
	LookBack = 0;
    fixZorro();
    float t;
	while(asset(loop(ASSETS))) {
	    string ticker = strf("%s",Asset);
        t = getThreshHold(ticker);
        if(price() < t){
            enterLong();
        }
        printf("\n ticker %s - current price %.2f - thresh hold %.2f", Asset, price(), getThreshHold(ticker));
	}
}
var getThreshHold(string ticker){
	float t;
	switch(ticker){
		case "BCG": t = 9.249400000000001;
			break;
		case "CMX": t = 15.8105;
			break;
		case "DLG": t = 1.3596000000000001;
			break;
		case "DRH": t = 7.3645000000000005;
			break;
		case "HAG": t = 4.7895;
			break;
		case "LDG": t = 6.9731;
			break;
		case "SCR": t = 7.1585;
			break;
		case "SZC": t = 29.2005;
			break;
		case "TDC": t = 9.671700000000001;
			break;
		case "TNI": t = 2.987;
			break;
		case "TSC": t = 2.987;
			break;
		case "TTB": t = 4.429;
			break;
		case "VHC": t = 45.9895;
			break;
	}
	return t;
}
