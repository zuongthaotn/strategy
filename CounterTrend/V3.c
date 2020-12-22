#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "AAA", "CMX", "HHS", "PDR"
#define ASSETS      RPM 
#define N           4
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
		case "AAA": t = 13.3385;
			break;
		case "CMX": t = 15.450000000000001;
			break;
		case "HHS": t = 4.964600000000001;
			break;
		case "PDR": t = 44.805;
			break;
	}
	return t;
}
