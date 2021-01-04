#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "CMX", "DAG", "DPG"
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
		case "CMX": t = 16.068;
			break;
		case "DAG": t = 7.004;
			break;
		case "DPG": t = 31.003000000000004;
			break;
	}
	return t;
}
