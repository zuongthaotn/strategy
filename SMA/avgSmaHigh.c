#include "Strategy/Magnus/fixZorro.h"

function run()
{
    int i;
    int sum = 0;

    StartDate = 2020;
	UnstablePeriod = 0;
	BarPeriod = 1440;           // 1 da = 60 *24
	MaxLong = MaxShort = 1;
    LookBack = 10;          // 2 weeks
    fixZorro();

}
