/*
 File: weather.c 
 Creator: Wizardchild (04/11/95)
 Description: 
  Filename constructions:
   SAVE_DIR+"weather."+weather+daytime
   eg. /players/wizardchild/closed/weather/weather.s0 for evening snow
  Weather options: 
   clear = b   cloud = c   hot   = h   ocast = o   
   rain  = r   snow  = s   humid = u   wind  = w
  Functions contained in this file:
   query_fname()     query_working()
   query_count()     query_daytime()
   query_season()    query_lastdaytime()
   query_weather()
   static error_msg(str)
   static weather_channel(str)
   static calc_time(calc_season)
   static manage_weather()
   static load_weather(new_weather)
  Other files:
   There are 8 weather types, 4 times of day.
   Hence, 32 files.
   Sunset/sunrise files have only 6 lines each
   Daytime/Nighttime files have 48 lines each
   There are 432 total weather lines in weather.* files
*/

/* Time string: Mon Apr 10 11:58:55 1995
#define SAVE_DIR "/players/wizardchild/closed/weather/"
#define MSGCOUNT 600   /* wait between messages - 10 minutes */

string *cfile;
string fname;

string **patterns; /* [4][13] */
string weather;
int season;
int daytime;
int lastdaytime;   /* keep track of changes in time */

int count;

status working;

query_fname()       { return fname;       }
query_count()       { return count;       }
query_season()      { return season;      }
query_weather()     { return weather;     }
query_working()     { return working;     }
query_daytime()     { return daytime;     }
query_lastdaytime() { return lastdaytime; }

static error_msg(str) {
  write_file(SAVE_DIR+"ERROR", "("+ctime(time())+"): "+str+"\n");
}
static weather_channel(str) {
  int i;
  object ob;
  ob = users();
  for(i = 0; i < sizeof(ob); i++)
    if(ob[i]->on_channel("weather"))
      tell_object(ob[i], str);
}  

/* returns: 0 on ok, -1 on season fail, -2 on time fail */
static calc_time(calc_season) {
  string str;
  int i;
  /* season */
  if(calc_season) {
    str = lower_case(extract(ctime(time()), 4, 6));
    season = -1;
    if(str == "dec" || str == "jan" || str == "feb")
      season = 0;
    if(str == "mar" || str == "apr" || str == "may")
      season = 1;
    if(str == "jun" || str == "jul" || str == "aug")
      season = 2;
    if(str == "sep" || str == "oct" || str == "nov")
      season = 3;
    if(season == -1) {
      season = 0;
      return -1;
    }
  }
  /* time */
  str = extract(ctime(time()), 11, 12);
  if(!sscanf(str, "%d", i))
    sscanf(str, " %d", i);
  if(!i)  
    return -1;
  if(i >= 22 || i < 7)  /* night   - 10pm to 6:59am */
    daytime = 0;        /*         - 9 hours        */                   
  if(i == 7)            /* sunrise - 7am to 7:59am  */
    daytime = 1;        /*         - 1 hour         */
  if(i >= 8 && i < 21)  /* daytime - 8am to 8:59pm  */
    daytime = 2;        /*         - 13 hours       */
  if(i == 21)           /* sunset  - 9pm to 9:59pm  */
    daytime = 3;        /*         - 1 hour         */
  return ((!daytime && !(i >= 22 || i < 7)) ? -2 : 0); 
}
static load_weather(new_weather) {
  int i;
  calc_time(0); /* recalculate the time to be safe */
  if(new_weather) {
    fname = SAVE_DIR+"weather.";
    i = random(sizeof(patterns[daytime]));
    weather = patterns[daytime][i];
    fname += weather+daytime;
  } else 
    fname = SAVE_DIR+"weather."+weather+daytime;
  if(!fname || file_size(fname) < 1)
    return -1; /* no weather file    */
  if(fname == SAVE_DIR+"weather.c")  
    return -2; /* big oopsies        */
  cfile = explode(read_file(fname), "\n");
  if(!cfile || !sizeof(cfile))
    return -3; /* error loading file */
  lastdaytime = daytime;
  return 0;  
}
static manage_weather() {
  calc_time(0);
  if(lastdaytime != daytime)
    load_weather();
  if(cfile && cfile[count]) 
    weather_channel(cfile[count]);
  else {
    weather_channel("The weather system is currently offline.\n");    
    working = 0;
    error_msg("manage_weather (count-"+count+",sizeof cf-"+sizeof(cfile)+")");
    return ; /* disable loop */
  }
  count = (count+1 >= sizeof(cfile) ? 0 : count+1);
  call_out("manage_weather", MSGCOUNT);
}
reset(arg) {
  int i;
  if(arg)
    return 0;
  count       = 0;
  season      = 0;
  daytime     = 0;
  lastdaytime = 0;
  working     = 1; /* we are working until we break */
  patterns = ( 
/* winter */ {"s","s","w","w","w","w","s","o","o","b","c","c","c"}, 
/* spring */ {"r","r","r","b","b","o","h","h","u","s","w","w","c"},
/* summer */ {"h","h","h","h","u","u","u","u","h","o","r","r","c"},
/* autumn */ {"r","b","b","o","o","o","w","w","w","s","c","h","h"});
  if((i = calc_time(1)) != 0) { 
    /* don't destruct! allow monitor to diagnose problem */
    error_msg("calc_time(1) in reset\n\t(seas-"+season+",dayt-"+
     daytime+",ret-"+i+")");
    working = 0;
  } else {
    if((i = load_weather(1)) != 0) {
      error_msg("load_weather(1) in reset\n\t(fname-"+fname+",sizeof cf-"+
       sizeof(cfile)+",ret-"+i+")");
      working = 0;
    } else
      call_out("manage_weather", MSGCOUNT);
  }
  if(!working && users()) 
    weather_channel("The weather system is currently offline.\n");
  else
    lastdaytime = daytime;
}
