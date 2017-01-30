#ifndef LPC_TIME_H_
#define LPC_TIME_H_ 1

/* Indices into the array returned from gmtime() and localtime(). */

#define TM_SEC    0  /* Seconds (0..59) */
#define TM_MIN    1  /* Minutes (0..59) */
#define TM_HOUR   2  /* Hours (0..23) */
#define TM_MDAY   3  /* Day of the month (1..31) */
#define TM_MON    4  /* Month of the year (0..11) */
#define TM_YEAR   5  /* Year (e.g.  2001) */
#define TM_WDAY   6  /* Day of the week (Sunday = 0) */
#define TM_YDAY   7  /* Day of the year (0..365) */
#define TM_ISDST  8  /* TRUE: Daylight saving time */

#define TM_MAX 9  /* Number of entries in the array */

#endif /* LPC_TIME_H_ */


#ifndef _sys_time_defs_h
#define _sys_time_defs_h

/* return values of query_moon() */
#define WAXING_MOON 1
#define FULL_MOON   2
#define WANING_MOON 3
#define NEW_MOON    4

#define WEEKDAYS ({ "sunday", "monday", "tuesday", "wednesday", "thursday", \
                    "friday", "saturday" })
#define SUNDAY     0
#define MONDAY     1
#define TUESDAY    2
#define WEDNESDAY  3
#define THURSDAY   4
#define FRIDAY     5
#define SATURDAY   6

#define MONTHS ({ "january", "february", "march", "april", "may", "june", \
                  "july", "august", "september", "october", "november", \
                  "december" })
#define JANUARY    0
#define FEBRUARY   1
#define MARCH      2
#define APRIL      3
#define MAY        4
#define JUNE       5
#define JULY       6
#define AUGUST     7
#define SEPTEMBER  8
#define OCTOBER    9
#define NOVEMBER  10
#define DECEMBER  11

#define SEASONS ({ "early spring", "late spring","summer", "early autumn", "late autumn","winter" })
#define ESPRING    0
#define LSPRING    1
#define SUMMER     2
#define EAUTUMN    3
#define LAUTUMN    4 
#define WINTER     5

#define SUN ({ "night", "dawn", "sunrise", "noon", "sunset", "dusk" })
#define NIGHT      0
#define DAWN       1
#define SUNRISE    2
#define NOON       3
#define SUNSET     4
#define DUSK       5

#endif  /* _sys_time_defs_h */

/*
 * sys/time_units.h
 * This file contains common time units measured in seconds.
 * Include it to use the names instead of the large numbers or costly formulas
 */

#ifndef _sys_time_units_h
#define _sys_time_units_h

#define ONE_SECOND             1
#define ONE_MINUTE            60  /* 60*ONE_SECOND */
#define ONE_HOUR            3600  /* 60*ONE_MINUE  */
#define ONE_DAY            86400  /* 24*ONE_HOUR   */
#define ONE_WEEK          604800  /* 7*ONE_DAY     */
#define ONE_MONTH        2629800  /* ONE_YEAR/12   */
#define ONE_YEAR        31557600  /* 365*ONE_DAY + 6*ONE_HOUR  */

#define HALF_MINUTE           30
#define HALF_HOUR           1800
#define HALF_DAY           43200
#define HALF_WEEK         302400
#define HALF_MONTH       1314900
#define HALF_YEAR       15778800

#define MOONDAY 89428  /* seconds ... off by .3 sek
                          should be exactly:
                          Month * 86400 / (Month - 86400) */

#endif

/*
 * This file contains the constants which can be given as thrid parameter
 * to the simul_efun set_timed_flag()
 */

#ifndef _sys_timed_flag_h
#define _sys_timed_flag_h

#define TF_MAXIMUM 0
#define TF_ADDING 1
#define TF_OVERRIDE 2

#endif /* _sys_timed_flag_h */

#ifndef _sys_timedep_h
#define _sys_timedep_h

#define TD_DAY2 ({ "day2" })
#define TD_DAY2_WHEN ({ 28800, 72000 })
#define TD_DAY2_WHAT ({ "day", "night" })

#define set_timedep2() set_default_depspace(TD_DAY2)


#define TD_DAY4 ({ "day4" })
#define TD_DAY4_WHEN ({ 21600, 25200, 64800, 68400 })
#define TD_DAY4_WHAT ({ "dawn", "day", "dusk", "night" })

#define set_timedep4() set_default_depspace(TD_DAY4)


#define TD_DAY6 ({ "day6" })
#define TD_DAY6_WHEN ({0,14400,28800,43200,57600,72000})
#define TD_DAY6_WHAT ({"midnight","morning","forenoon","afternoon","evening","night"})

#define set_timedep6() set_default_depspace(TD_DAY6)


#define TD_DAY8 ({ "day8" })
#define TD_DAY8_WHEN ({0,3600,18000,28800,43200,46800,64800,72000})
#define TD_DAY8_WHAT ({"midnight","late night","morning","forenoon","noon","afternoon","evening","night"})

#define set_timedep8() set_default_depspace(TD_DAY8)


#define TD_SUN ({ "sun" })
#define TD_SUN_WHEN ({0,18000,25200,28800,39600,46800,64800,68400,72000})
#define TD_SUN_WHAT ({"late night","dawn","sunrise","forenoon","noon","afternoon","sunset","dusk","night"})


#define TU_MOON     "query_tu_moon"
#define TU_MOONDAY  "query_tu_moontime"
#define TU_MONTH    "query_tu_month"
#define TU_WEEKDAY  "query_tu_weekday"


#define TD_MOON4 ({ "moon4" })
#define TD_MOON4_WHEN ({ 16, 165, 196, 345 })
#define TD_MOON4_WHAT ({ "waxing", "full", "waning", "new" })


#define TD_YEAR4 ({ "year4" })
#define TD_YEAR4_WHEN ({ 2, 5, 8, 11 })
#define TD_YEAR4_WHAT ({ "spring", "summer", "autumn", "winter" })


#define TD_WEEKDAY ({ "weekday" })
#define TD_WEEKDAY_WHEN ({ 0, 1, 2, 3, 4, 5, 6 })
#define TD_WEEKDAY_WHAT ({"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"})


// Defaults
#define DEFAULT_DEPSPACE ({ 0, 0, TD_DAY2, 0, TD_DAY4, 0, TD_DAY6, 0, TD_DAY8})

#define TD_WHAT ([ TD_DAY2[0]     : TD_DAY2_WHAT,   \
                   TD_DAY4[0]     : TD_DAY4_WHAT,   \
                   TD_DAY6[0]     : TD_DAY6_WHAT,   \
                   TD_DAY8[0]     : TD_DAY8_WHAT,   \
                                                    \
                   TD_MOON4[0]    : TD_MOON4_WHAT,  \
                   TD_WEEKDAY[0]  : TD_WEEKDAY_WHAT,\
                   TD_YEAR4[0]    : TD_YEAR4_WHAT,  \
                   TD_SUN[0]      : TD_SUN_WHAT ])

#define TD_WHEN ([ TD_DAY2[0]     : TD_DAY2_WHEN,   \
                   TD_DAY4[0]     : TD_DAY4_WHEN,   \
                   TD_DAY6[0]     : TD_DAY6_WHEN,   \
                   TD_DAY8[0]     : TD_DAY8_WHEN,   \
                                                    \
                   TD_MOON4[0]    : TD_MOON4_WHEN,  \
                   TD_WEEKDAY[0]  : TD_WEEKDAY_WHEN,\
                   TD_YEAR4[0]    : TD_YEAR4_WHEN,  \
                   TD_SUN[0]      : TD_SUN_WHEN ])

#define TD_WHICH ([ TD_MOON4[0]   : TU_MOON,        \
                    TD_WEEKDAY[0] : TU_WEEKDAY,     \
                    TD_YEAR4[0]   : TU_MONTH ])

#endif  // _sys_timedep_h

#ifndef _sys_timezone_h
#define _sys_timezone_h

#define TZ_OFFSET 1237113000  // The TZ_OFFSET for the current age
#define TZ_SHIFT 3            // the mud runs 2^3 times faster than real time

#endif  // _sys_timezone_h

