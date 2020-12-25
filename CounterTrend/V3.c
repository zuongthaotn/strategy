#include "Strategy/Magnus/fixZorro.h" 
#define RPM         "ACB", "BFC", "BID", "BWE", "CII", "CMX", "CTG", "DAG", "DPG", "DPM", "DRC", "HAP", "HHS", "HT1", "HVN", "PHR", "PLX", "STB", "TCH", "VRE"
#define ASSETS      RPM 
#define N           20
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
		case "BFC": t = 16.119500000000002;
			break;
		case "BID": t = 45.217;
			break;
		case "BWE": t = 30.745500000000003;
			break;
		case "CII": t = 19.5185;
			break;
		case "CMX": t = 15.450000000000001;
			break;
		case "CTG": t = 33.166000000000004;
			break;
		case "DAG": t = 6.901000000000001;
			break;
		case "DPG": t = 29.355;
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
		case "HVN": t = 26.677;
			break;
		case "PHR": t = 63.653999999999996;
			break;
		case "PLX": t = 50.985;
			break;
		case "STB": t = 16.274;
			break;
		case "TCH": t = 19.7245;
			break;
		case "VRE": t = 29.458000000000002;
			break;
	}
	return t;
}
