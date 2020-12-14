// Counter trend trading ///////////////////
#include "Strategy/Magnus/fixZorro.h"
#include "Strategy/Magnus/AgainstTrend/methods.h"

function run()
{
	UnstablePeriod = 0;
	BarPeriod = 1440;           // 1 day = 60 *24
	MaxLong = MaxShort = 1;
    fixZorro();

    method01();

	set(PLOTNOW);
	set(LOGFILE); // log all trades
}

