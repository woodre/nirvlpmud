/*
    basic/time.c - time conversion routines.
    Jan 1992 by marion@cs.tu-berlin.de

    Defines:

    int *time_val (int)
    int *heart_val (int)
        Returns an array of
          ({ sec, min, hours, monthday, month, year, weekday, dayofyear,
             TM_ISDST || 0, days })
        converted from the first argument, which is a time in seconds or
        a heart beat value, respectively.
        old:({sec, min, hours, days, year, dayofyear, month, weekday, monthday})
    
    string time_long (int)
    string heart_long (int)
        Returns a string formatted as the output for the player age from
        the score command. The argument is the same as to *_val.
    
    string time_short (int)
    string heart_short (int)
        Returns a string formatted as the output for the player age from
        the people command. The argument is the same as to *_val.

  completely rewritten, Coogan, 04-Nov-2001
*/

#pragma strong_types

#include <time_units.h>  // Coogan, 14-Mar-2000
#include <time.h>        // Coogan, 03-Nov-2001
#include <server.h>      // Coogan, 05-Nov-2001

private mixed *time_month;
private int last_time, *gmtime_result, trunc;  // Coogan, 03-Nov-2001


int* time_val(int t) {
  if (!t || t != last_time) {
    last_time = t;
#if __EFUN_DEFINED__(gmtime)
    gmtime_result = gmtime(t);

    // we defined, that the very first day of an age is a monday.
    gmtime_result[6] = (gmtime_result[6] + 4) % 7;

    // 1970 was the reference point of gmtime() where time == 0
    gmtime_result[5] -= 1970;

    gmtime_result += ({ t / ONE_DAY });   // add the absolut No. of days
#else
    if (!time_month) {
      time_month = ({
           ({ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 }),
           ({ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 }) });
    }
    gmtime_result = allocate(10);
    if (t >= 86400) { gmtime_result[9]       = t / 86400; t %= 86400; }
    if (t >= 3600)  { gmtime_result[TM_HOUR] = t / 3600;  t %= 3600; }
    if (t >= 60)    { gmtime_result[TM_MIN]  = t / 60;    t %= 60; }
                    { gmtime_result[TM_SEC]  = t; }
    gmtime_result[TM_YEAR] = gmtime_result[9] / 1424;       /* switch years */
    gmtime_result[TM_YEAR] = (gmtime_result[9] - gmtime_result[TM_YEAR]) / 365;
                                                            /* year */
    gmtime_result[TM_YDAY] = gmtime_result[9] - gmtime_result[TM_YEAR]*365 -
                             gmtime_result[TM_YEAR]/4;      /* day of year */
    trunc = !(gmtime_result[TM_YEAR] % 4);
    gmtime_result[TM_MON] = gmtime_result[TM_YDAY] / 31;    /* month */
    while (gmtime_result[TM_MON] < 11 &&
           gmtime_result[TM_YDAY] > time_month[trunc][gmtime_result[TM_MON]+1])
      gmtime_result[TM_MON]++;
    gmtime_result[TM_WDAY] = gmtime_result[9] % 7;          /* day of week */
    gmtime_result[TM_MDAY] = gmtime_result[TM_YDAY] -
                               time_month[trunc][gmtime_result[TM_MON]];
#endif
  }
  return gmtime_result;
}

string time_long(int t) {
  string ret;
  int *val;

  if (t <= 0)
    return "no time";
#define PL(v) ({"s",""})[(v)==1]
#define BL(s) ((s)?" "+(s):"")
  val = time_val (t);
  if (val[TM_SEC])  ret = val[TM_SEC] +" second"+PL(val[TM_SEC]);
  if (val[TM_MIN])  ret = val[TM_MIN] +" minute"+PL(val[TM_MIN]) +BL(ret);
  if (val[TM_HOUR]) ret = val[TM_HOUR]+" hour"  +PL(val[TM_HOUR])+BL(ret);
  if (val[9])       ret = val[9]      +" day"   +PL(val[9])      +BL(ret);
  return ret;
}

string time_short(int t) {
  if (t/1000 >= ONE_MONTH)  return (t/ONE_YEAR)   + "Y";
  if (t >= ONE_MONTH &&
      t >= 1000 * ONE_DAY)  return (t/ONE_MONTH)  + "M";
  if (t >= ONE_DAY)         return (t/ONE_DAY)    + "D";
  if (t >= ONE_HOUR)        return (t/ONE_HOUR)   + "h";
  if (t >= ONE_MINUTE)      return (t/ONE_MINUTE) + "m";
                            return to_string(t)   + "s";
}

int *heart_val(int t) {
  return time_val(2 * t);
}

string heart_long(int t) {
  return time_long(2 * t);
}

string heart_short(int t) {
  return time_short(2 * t);
}

string mtime(int t) {
  int *time;

  if (t)
    time = time_val(t);
  else
    time = time_val(SE_TIME->query_time());

  return sprintf("%s %s %:2d %:02d:%:02d:%:02d %:4d",
           ({"Sun", "Mon","Tue","Wed","Thu","Fri","Sat"})[time[TM_WDAY]],
           ({"Jan","Feb","Mar","Apr","May","Jun",
             "Jul","Aug","Sep","Oct","Nov","Dec"})[time[TM_MON]],
           time[TM_MDAY], time[TM_HOUR], time[TM_MIN], time[TM_SEC],
           time[TM_YEAR]);
}

