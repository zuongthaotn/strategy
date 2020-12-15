#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "DRH", "HAR", "OGC", "PAN", "TSC", "VCI"
#define ASSETS      RPM 
#define N           6
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
	 case "DRH": t = 7.3645000000000005;
		break;
	 case "HAR": t = 4.532000000000001;
		break;
	 case "OGC": t = 7.2615;
		break;
	 case "PAN": t = 21.424000000000003;
		break;
	 case "TSC": t = 2.9767;
		break;
	 case "VCI": t = 44.0325;
		break;
	}
	 return t;
	}
