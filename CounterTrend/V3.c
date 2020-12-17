#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "APH", "ITA", "SCR"
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
//        printf("\n ticker %s - current price %.2f - thresh hold %.2f", Asset, price(), getThreshHold(ticker));
	}
}
var getThreshHold(string ticker){
	float t;
	switch(ticker){
		case "APH": t = 87.035;
			break;
		case "ITA": t = 5.4178;
			break;
		case "SCR": t = 7.1585;
			break;
	}
	return t;
}
