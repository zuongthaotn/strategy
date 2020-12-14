// Trend Trading ///////////////////
#include "Strategy/Magnus/fixZorro.h"
#include "Strategy/Magnus/BreakOut/methods.h"

function run()
{
	UnstablePeriod = 0;
	BarPeriod = 1440;           // 1 day = 60 *24
	MaxLong = MaxShort = 1;
    fixZorro();

    method02();

	set(PLOTNOW);
	set(LOGFILE); // log all trades
}

