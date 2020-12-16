#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "CMX", "DRH", "SCR", "SZC", "TDC"
#define ASSETS      RPM 
#define N           5
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
		case "CMX": t = 15.8105;
			break;
		case "DRH": t = 7.3645000000000005;
			break;
		case "SCR": t = 7.1585;
			break;
		case "SZC": t = 29.2005;
			break;
		case "TDC": t = 9.671700000000001;
			break;
	}
	return t;
}
