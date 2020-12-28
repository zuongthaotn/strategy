#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "ACB", "ANV", "BFC", "BID", "BVH", "BWE", "CTG", "DAG", "DPG", "DPM", "DRC", "HAP", "HHS", "HT1", "PHR", "STB", "TCH", "VRE"
#define ASSETS      RPM 
#define N           18
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
		case "ACB": t = 27.295;
			break;
		case "ANV": t = 22.454;
			break;
		case "BFC": t = 16.119500000000002;
			break;
		case "BID": t = 45.217;
			break;
		case "BVH": t = 58.504;
			break;
		case "BWE": t = 30.745500000000003;
			break;
		case "CTG": t = 33.166000000000004;
			break;
		case "DAG": t = 6.9628;
			break;
		case "DPG": t = 29.4065;
			break;
		case "DPM": t = 18.128000000000004;
			break;
		case "DRC": t = 21.939;
			break;
		case "HAP": t = 6.0358;
			break;
		case "HHS": t = 5.2015;
			break;
		case "HT1": t = 16.892;
			break;
		case "PHR": t = 63.653999999999996;
			break;
		case "STB": t = 16.274;
			break;
		case "TCH": t = 19.776;
			break;
		case "VRE": t = 29.458000000000002;
			break;
	}
	return t;
}
