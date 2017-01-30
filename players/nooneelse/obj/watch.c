/*
 watch.c - an alarm clock
*/

inherit "obj/armor";

/* 24 hour clock stuff */
int alarm_is_set, hour, hour_am_pm, minute, time_zone_difference;
/* 12 hour clock stuff */
int time_now, time_and_zone, days, th, hx, hr, tmin, min, seconds;

init() {
  ::init();

  add_action("set_alarm",    "alarm");
  add_action("time_display", "time");
  add_action("zone_time",    "zone");
}

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("watch");
  set_short("A tin watch on a nickel chain");
  set_long(
    "....................................................................\n"+
    ": A timekeeping device. It has the following functions:            :\n"+
    ":                                                                  :\n"+
    ": Alarm                                                            :\n"+
    ":   Used to set, examine or turn off an alarm.                     :\n"+
    ":     . 'alarm' returns the time the alarm is set for,             :\n"+
    ":             (or tells you that it isn't set).                    :\n"+
    ":     . 'alarm off' will turn the alarm off.                       :\n"+
    ":     . 'alarm hh:mm' sets the alarm (hh:mm is in 24 hour format)  :\n"+
    ":                   (ie: alarm 13:13 sets it for 1:13pm)           :\n"+
    ":                                                                  :\n"+
    ": Time                                                             :\n"+
    ":   Displays the current game time.                                :\n"+
    ":                                                                  :\n"+
    ": Zone                                                             :\n"+
    ":   . 'zone' returns the currently set time zone difference.       :\n"+
    ":   . 'zone hh:mm' sets the difference in hours and minutes.       :\n"+
    ":                  (ie: zone -2:00 sets the watch back 2 hours &   :\n"+
    ":                       zone  1:00 sets the watch up 1 hour)       :\n"+
    "....................................................................\n\n");
  set_type("amulet");
  set_ac(1);
  set_weight(1);
  set_value(0);
}

set_alarm(str) {
  int num, dat, sec, year, phour, pminute;
  string name, dow, mon;

  if (!str) {
    if (!alarm_is_set) {
      write("You haven't set the alarm!\n");
      return 1;
    }
    write("The alarm is set for ");
    show_alarm(hour, minute);
    return 1;
  }
  if (str == "off") {
    if (remove_call_out("alarm") == -1) {
      write("You didn't have the alarm set!\n");
      return 1;
    }
    write("You turn the alarm off.\n");
    alarm_is_set=0;
    return 1;
  }
  if (alarm_is_set) {
    write("The alarm is already set for ");
    show_alarm(hour, minute);
    return 1;
  }
  if (sscanf(str, "%d:%d", hour, minute) != 2) {
    write("Invalid time.\n");
    return 1;
  }
  sscanf(ctime(time()+time_zone_difference), "%s %s %d %d:%d:%d %d",
         dow, mon, dat, phour, pminute, sec, year);
  num = (3600 * (hour - phour)) + (60 * (minute - pminute)) - sec;
  if (num < 0) num += 86400;
  call_out("alarm", num, this_player()->query_real_name());
  write("You set the alarm for ");
  show_alarm(hour, minute);
  alarm_is_set=1;
  return 1;
}

time_display() {
  write("The current game time is "+ctime(time())+"\n");
  if (time_zone_difference!=0)
    write("The time in your zone is "+ctime(time()+time_zone_difference)+"\n");

/* 12 hour clock */
/*
  time_now = time();
  time_and_zone = time_now + time_zone_difference*3600 + 19*3600;
  th = time_and_zone/3600;
   days = (th)/24;
   hx = th - days*24;
   if (hx > 12) hr = hx - 12;
   if (hx < 12) hr = hx;
   if (hx == 0) hr = 12;
   tmin = time_and_zone/60;
   min = tmin - days*24*60 - hx*60;
   seconds = time_and_zone - days*24*3600 - hx*3600 - min*60;
   write(" --- "+hr+":");
   if (min < 10) write("0");
   write(min);
   if (hr > 12)
     write("pm\n");
   else
     write("am\n");
*/
/* end of 12 hour clock */

/* show the time the alarm is set for */
  set_alarm();
  return 1;
}

zone_time(str) {
  int h, m, diff_h, diff_m;

  diff_h = time_zone_difference / 3600;
  diff_m = time_zone_difference - (3600 * diff_h);
  if (!str) {
    write("Time difference is currently " + diff_h + ":");
    if (diff_m < 10) write("0");
    write(diff_m + ".\n");
    return 1;
  }
  if (sscanf(str, "%d:%d", h, m) != 2) {
    write("Bad time difference.  Use: hh:mm\n");
    return 1;
  }
  time_zone_difference = (3600 * h) + (60 * m);
  write("Time difference is now " + h + ":");
  if (m < 10) write("0");
  write(m + ".\n");
  return 1;
}

alarm(owner) {
  tell_object(find_player(owner),
   "\n\n\nThe alarm on your watch has gone off!\n\n\n");
  alarm_is_set=0;
  return 1;
}

show_alarm(hour,minute) {
  if (!hour)
    write("00");
  else
    write(hour);
  write(":");
  if (minute < 10) write("0");
  write(minute + "\n");
/* 12 hour clock */
/*
  if (hour > 12)
    hour_am_pm=hour - 12;
  else
    hour_am_pm=hour;
  write(" --- "+hour_am_pm+":");
  if (minute < 10) write("0");
  write(minute);
  if (hour > 12)
    write("pm\n");
  else
    write("am\n");
*/
/* end of 12 hour clock */
  return 1;
 }
