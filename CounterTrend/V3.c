#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "BFC", "BWE", "DAG", "DPM", "HAP", "HT1", "PHR", "PVT"
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
		case "BFC": t = 16.119500000000002;
			break;
		case "BWE": t = 30.745500000000003;
			break;
		case "DAG": t = 6.9628;
			break;
		case "DPM": t = 18.128000000000004;
			break;
		case "HAP": t = 6.0358;
			break;
		case "HT1": t = 16.892;
			break;
		case "PHR": t = 63.653999999999996;
			break;
		case "PVT": t = 12.978;
			break;
	}
	return t;
}
