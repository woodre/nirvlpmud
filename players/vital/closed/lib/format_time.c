#pragma strict_types
#pragma save_types

string format_time(int t) {
  int val;
  int sec,min,hr,day;
  sec = (t - ((t / 60) * 60));
  val = t - sec;
  val = val / 60; /* val is now the total in minutes */
  min = (val - ((val / 60) * 60));
  val = val/60;   /* val is now the total in hours */
  hr = (val - ((val / 24) * 24));
  val = val/24;
  day = val;
  return day+" days, "+hr+" hours, "+min+" minutes, and "+sec+" seconds";
}
