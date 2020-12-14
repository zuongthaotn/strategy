// Strategy template ///////////////////////

function run() 
{
	set(LOGFILE);
	BarPeriod = 5;
	MaxLong = 10;
	asset("KOS");
	vars Prices = series(price());
	if(Prices[0] < 29.8){
		enterLong();
	}
}