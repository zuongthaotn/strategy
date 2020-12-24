#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "CMX", "DPG", "DPM", "GEX", "HAP", "HHS", "PHR", "TCH"
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
		case "CMX": t = 15.450000000000001;
			break;
		case "DPG": t = 29.252;
			break;
		case "DPM": t = 18.230999999999998;
			break;
		case "GEX": t = 21.218000000000004;
			break;
		case "HAP": t = 6.0358;
			break;
		case "HHS": t = 5.0779;
			break;
		case "PHR": t = 64.375;
			break;
		case "TCH": t = 19.467;
			break;
	}
	return t;
}
