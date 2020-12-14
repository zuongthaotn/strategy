// Trend Trading ///////////////////
#include "Strategy/Magnus/fixZorro.h"
#include "Strategy/Magnus/FollowTrend/methods.h"

function run()
{
	UnstablePeriod = 0;
	BarPeriod = 1440;           // 1 day = 60 *24
	MaxLong = MaxShort = 1;
    LookBack = 10;          // 2 weeks
    fixZorro();

    method04();

	set(PLOTNOW);
	set(LOGFILE); // log all trades
}

