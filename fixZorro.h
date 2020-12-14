#ifndef _VN_H
#define _VN_H

#include <default.c>

function fixZorro()
{

    static int VNHolidays[27] = {
    0101,
    0430,
    0501,
    0902,
    /** 2019 */
    20190202,   // TET...
    20190203,
    20190204,
    20190205,
    20190206,
    20190207,
    20190208,
    20190209,
    20190210,   // ...TET
    /** Endl 2019 */
    20200123, // TET...
    20200124,
    20200127,
    20200128,
    20200129, // ...TET
    20200402, // GIO TO
    20210210, // TET...
    20210211,
    20210212,
    20210215,
    20210216, // ...TET
    20210421, // GIO TO
    20210503, // 0501
    20220103 // 0101
  };
  Holidays = VNHolidays;
  // VN Market Time
//  StartWeek = 1;
//  EndWeek = 5;
  StartMarket = 0200; // 9:00 GMT+7
  EndMarket = 0745; // 14:45 GMT+7
  MinutesPerDay = 240; // 9:15->11:30 & 13:00->14:45 GMT+7

  // VN Risk Free Rate: https://zorro-trader.com/manual/en/spread.htm
  // if (Test) Interest = 8.;

//  BarMode = BR_WEEKEND|BR_MARKET|BR_SLEEP|BR_LEISURE;
  BarMode = BR_WEEKEND+BR_MARKET+BR_SLEEP+BR_LEISURE;

  // https://zorro-trader.com/manual/en/loadstatus.htm
  SaveMode = SaveMode|SV_STATS;

  // Day Market Time
  HistoryZone = 7; // GMT+7
  StartMarket = 0215; // 9:15 GMT+7
  EndMarket = 0747; // 14:47 GMT+7
  // Day Trading
//  BarPeriod = 1440;    // 1 day bars
  BarOffset = 465;  // 0745 - VN Market Closed
  g->tDayOffset = 30./86400; // 30s Ahead

}