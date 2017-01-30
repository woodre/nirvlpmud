/* 
   Copyright (c) 1990,91 by Raistlin (john@stat.tamu.edu).
   All rights reserved.  Permission given to modify only those
   parts clearly marked.  Any other modifications must be sent
   to the author first.  Any distribution of this code must go
   through the author.
 */ 

/* Modify this to be your time zone.  if you aren't subject to */
/* daylight's saving time, don't define TIME_ZONE2 */
#define TIME_ZONE  "CST"
#define TIME_ZONE2 "CST"

string uptime;
static string present_time;
static int p_hour, p_min;
static int started;

int starttime;
int uplimit;
void reset(int arg) {
  if(arg)
    return;
  set_heart_beat(1);
  started = 0;
  uptime = ctime(time());
  starttime = time();
#ifndef __LDMUD__ /* Rumplemintz */
  save_object("log/upsince");
#else
  save_object("log/upsince_ld");
#endif
/* Commented out to  see if it stops mystery saving in DR in ld format -Bp
  save_object("/log/upsince");
  save_object("log/upsince", 0);
*/
}

/* 10/10/06 Earwax: adding this for testing/debugging purposes */
void test_me() { starttime -= (26 * 3600); }
void heart_beat() {
  string junk1, junk2, junk3;
  int junk4;
   int upptime;

  if (started && !find_object("/obj/shut.c")) started = 0;
  if(started) return;
  present_time = ctime(time());
  sscanf(present_time,"%s %s %d %d:%d:%s",junk1,junk3,junk4,p_hour,p_min,junk2);
  if(p_hour == 5 && p_min == 55 && !started) {
    log_file("SHUTDOWN","Game Clock:4:55amCT "+ctime(time())+" Shutting down game.\n");
    started = 1;
    "/obj/shut"->shut(10);
/*
    log_file("SHUTDOWN", "Clock shutting down game at:  "+ctime(time())+"\n");
*/
  } 
/*  Restart game if up for certain amount of time (8 hrs)  -Bp */
  if (started) return;
   if(p_hour > -1 && p_hour < 77) {
     upptime = time() - starttime;
/*
uplimit = 8 * 3600;
uplimit = 12 * 3600;
*/
uplimit = 25 * 3600;
 if (upptime > uplimit && !started) {
    started = 1;
    "/obj/shut"->shut(10);
  } 
}
  return;
}

string short() { 
  return "The Game Clock";
}

int id(string str) { 
  return (str == "clock") || str == ("inscription"); 
}

void long() {
  write("This is Nirvana's game clock.  It has a big face on it showing\n");
  write("the current time and there is a small gold plaque on the base\n");
  write("with an inscription on it.  Use 'read' to look at time or the\n");
  write("inscription.\n");
}

void init() {
   if(environment() != environment(this_player())) 
     return 0;
#ifndef __LDMUD__ /* Rumplemintz */
   add_action("show_time"); add_verb("read");
#else
  add_action("show_time", "read");
#endif
}

void inscription() {
  write("You see a plate similar to one of those 'Made in Korea' Stamps.\n" +
  "The inscription says :\nCompliments of Raistlin on Darker Realms.\n");
  return;
}

string parse_time(string str) {
   string printstring, day, month, ampm, tmp, year, minute, second;
   string tmphour, tmpdate;
   int hour, hour2, date;

   if (!str) return 0;

   sscanf(str, "%s %s %s", day, month, tmp);
   while(tmp[0] == ' ')
#ifndef __LDMUD__ /* Rumplemintz */
      tmp = extract(tmp, 1);
   sscanf(tmp, "%s %s:%s:%s %s", tmpdate, tmphour, minute, second, year);
   hour = atoi(tmphour);
   date = atoi(tmpdate);
#else
    tmp = tmp[1..];
    sscanf(tmp, "%s %s:%s:%s %s", tmpdate, tmphour, minute, second, year);
    hour = to_int(tmphour);
    date = to_int(tmpdate);
#endif
   if (hour >= 12)
      ampm = "pm";
   else
      ampm = "am";
   if(hour == 0)
     hour = 12;
   else 
     if(hour > 12) 
       hour -= 12;
   printstring = hour+":";
   printstring += minute+":";
   printstring += second+" ";
   printstring += ampm + " " +day+" "+month+" "+date+" "+year;
   return printstring;
}

void read_time() {
  string str, a, b;
  
  say(this_player()->query_name() + " reads the clock.\n",this_player());
  write("The time is: "+parse_time(ctime(time()))+"\n");
  restore_object("log/upsince");
  str = uptime; 
  if(!str) 
    return;
  write("The game has been up since: "+parse_time(str)+"\n");
  return;
}

int show_time(string arg)
{
  if(!id(arg)) 
    return 0;
  if(arg == "inscription") {
    inscription();
    return 1;
  }
  read_time();
  return 1;
}

