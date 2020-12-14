////////////////////////////////////////////////
// Convert price history from .csv to .t6
// The Format string determines the CSV format (see examples)
////////////////////////////////////////////////

#define SPLIT_YEARS	// split into separate years
//#define FIX_ZONE	-1 // add a time zone difference, f.i. for converting CST -> EST

// Downloaded line format "2019-12-27,38.60,38.60,37.70,37.70,3930,37.70,0"
string Format = "+%Y-%m-%d,f3,f1,f2,f4,f6,f5,"; // unadjusted

// cophieu68 line format (from data/Prices/VNX)
// <Ticker>,<DTYYYYMMDD>,<OpenFixed>,<HighFixed>,<LowFixed>,<CloseFixed>,<Volume>,<Open>,<High>,<Low>,<Close>,<VolumeDeal>,<VolumeFB>,<VolumeFS>
// FPT,20191206,55.00,55.40,54.70,55.00,556160,55.00,55.40,54.70,55.00,0,0,0
// string Format = ",%Y%m%d,f3,f1,f2,f4,f6,,,,f5,,,";

// tvsi line format "2018-11-19,37.6,37.8,37.4,37.7,396020"
// string Format = "+%Y-%m-%d,f3,f1,f2,f4,f6";

// HISTDATA line format: "20100103 170000;1.430100;1.430400;1.430100;1.430400;0"
// string Format = "+%Y%m%d %H%M%S;f3;f1;f2;f4;f6;f";

// YAHOO line format "2015-05-29,43.45,43.59,42.81,42.94,10901500,42.94"
//string Format = "%Y-%m-%d,f3,f1,f2,f4,f6,f5"; // unadjusted

// TRADESTATION line format "06/30/2016,17:00:00,2086.50,2086.50,2086.50,2086.50,319,0"
//string Format = "+%m/%d/%Y,%H:%M:%S,f3,f1,f2,f4,f6,f5";

// STK line format "12/23/2016,2300.00,SPY, 225.63, 225.68, 225.72, 225.62,1148991"
//string Format = "+-%m/%d/%Y,%H%M,,f3,f4,f1,f2,f6,f";

function main()
{
	int Records = dataParse(1,Format,strf("%s.csv", Asset));
	printf("\n%d lines read",Records);
#ifdef FIX_ZONE
	int i;
	for(i=0; i<Records; i++)
		dataSet(1,i,0,dataVar(1,i,0)+FIX_ZONE/24.);
#endif
#ifndef SPLIT_YEARS
	if(Records) dataSave(1,strf("%s.t6", Asset));
#else
	int i, Start = 0, Year, LastYear = 0;
	for(i=0; i<Records; i++) {
		Year = atoi(strdate("%Y",dataVar(1,i,0)));
		if(!LastYear) LastYear = Year;
		if(i == Records-1) { // end of file
			LastYear = Year; Year = 0;
		}
		if(Year != LastYear) {
			string NewName = strf("%s_%4i.t6",Asset,LastYear);
			printf("\n%s",NewName);		
			dataSave(1,NewName,Start,i-Start);
			Start = i;
			LastYear = Year;
		}
	}
#endif
}