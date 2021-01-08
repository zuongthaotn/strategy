#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "BFC", "BMI", "DPG", "HPX", "KDC"
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
		case "BFC": t = 17.1495;
			break;
		case "BMI": t = 31.260500000000004;
			break;
		case "DPG": t = 32.548;
			break;
		case "HPX": t = 28.84;
			break;
		case "KDC": t = 37.801;
			break;
	}
	return t;
}
