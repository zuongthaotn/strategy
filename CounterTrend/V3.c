#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "BFC", "CMX", "CTI", "DCM", "DPM", "FMC", "GEX", "HT1"
#define ASSETS      RPM 
#define N           8
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
		case "BFC": t = 16.4285;
			break;
		case "CMX": t = 15.450000000000001;
			break;
		case "CTI": t = 14.42;
			break;
		case "DCM": t = 12.669;
			break;
		case "DPM": t = 18.230999999999998;
			break;
		case "FMC": t = 35.947;
			break;
		case "GEX": t = 21.218000000000004;
			break;
		case "HT1": t = 16.9435;
			break;
	}
	return t;
}
