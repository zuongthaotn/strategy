#include "Strategy/Magnus/fixZorro.h"
#define RPM         "DBC", "HAR", "KSB", "VND"
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
	 case "DBC": t = 43.26;
		break;
	 case "HAR": t = 4.284800000000001;
		break;
	 case "KSB": t = 27.604000000000003;
		break;
	 case "VND": t = 19.261;
		break;
	}
	 return t;
	}
