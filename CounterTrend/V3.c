#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "APH", "EVG", "FMC", "FTS", "TPB", "VRE"
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
		case "APH": t = 83.43;
			break;
		case "EVG": t = 5.8915999999999995;
			break;
		case "FMC": t = 35.638000000000005;
			break;
		case "FTS": t = 13.6475;
			break;
		case "TPB": t = 22.7115;
			break;
		case "VRE": t = 28.943;
			break;
	}
	return t;
}
