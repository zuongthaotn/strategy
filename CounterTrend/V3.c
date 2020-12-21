#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "CMX", "FTS", "VHC"
#define ASSETS      RPM 
#define N           3
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
		case "CMX": t = 16.119500000000002;
			break;
		case "FTS": t = 13.699000000000002;
			break;
		case "VHC": t = 42.951;
			break;
	}
	return t;
}
