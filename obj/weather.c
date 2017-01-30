/*
 * DO NOT CLONE THIS OBJECT
 *
 * Climate:  i.e. general weather pattern
 *
 *  0 : normal
 *  1 : bad
 *  2 : tropic
 *  3 : jungle
 *  4 : desert
 *  5 : arctic
 *  6 : sea
 *
 * This object runs two call_outs, one to change night & day, and one to
 * change the weather
 *
 * i.e. change_time(), and change_weather().
 *
 * /inherit/room2 - takes care of it's own light by fix_day() which is
 * triggered in it's init() - i.e. when a player enters a room
 */

int day;
int day_status;     /* -1 night, 0 twilight, 1 day */
status light_adj;   /* 1 sunrise, -1 sunset */
int dawn_time;      /* last dawn, real time */


/****************************************************************************
 * fn specs
 */

/* weather */

string query_all_weather(int climate, int weather); /* weather string */
varargs void change_weather(int climate_type);      /* change weather */
int query_weather();                                /* weather number */
int query_next_weather();                           /* next weather change */

/* time & light */

static void cycle_light();                          /* day->night->day-> */
void change_time();                                 /* cycle */
void mud_time();                                    /* 'mud' clock time */

status query_night();
status query_day();
status query_dawn();
status query_dusk();

int query_light_adjustment();                       /* light adjust +1, -1 */

/****************************************************************************
 * reset - startup this object
 */

void reset(status arg) {
  if (arg) return;

  light_adj = 1;
  change_time();
  change_weather();
}


/****************************************************************************
 * weather - someone should extend the climate strings
 */

#define WEATHER_SIZE          8                    /* largest climate type */
#define CHANGE_WEATHER_PERIOD 1350                 /* every 45 minutes */

int current_weather, next_weather;

string query_all_weather(int climate, int weather) {
  mixed *all_weather;

  if(climate == 3) climate = 2; /* jungle == tropic */
  if(climate == 1) climate = 0;
 
  all_weather = ({
  
/* climate - default (climate == 0) */
({        /* day */                          /* night */
  ({"The sun is shining pleasently.\n", "The moon is beaming down.\n"}),
  ({"The sun is shining.\n",            "The moon is shining.\n" }),
  ({"The sun is blazing down.\n", "The night is pleasently warm.\n"}),
 ({"The sky is clear except for a few clouds.\n","It drizzles a little.\n", }),
  ({"The sun is obscured by some clouds.\n",
    "The moon is obscured by some clouds.\n"}),
  ({"It is raining.\n", "It is raining.\n",}),
  ({"The rain is pouring down.\n","The rain is pouring down.\n",}),
  ({"There is a big thunderstorm.\n","There is a big thunderstorm.\n",}),
}),

/* climate - bad (climate == 1) */
({

}),


/* climate - jungle (climate == 2) */
({
  ({ "It is very humid.\n", "It is a bit chilly.\n",}),
  ({"A warm wind blows some clouds across the sky.\n" +
    "One of them reminds you of an elephant.\n",
    "A warm wind blows some clouds across the starry sky.\n" +
    "One of them reminds you of an elephant.\n",}),
  ({"Heavy jungle mist falls from the dense canopy above.\n",
    "Heavy jungle mist falls from the dark canopy above.\n",}),
  ({"The balmy conditions stifle you.\n",
    "The balmy conditions stifle you.\n",}),
  ({"The clouds look like rain.\n","The clouds look like rain.\n",}),
  ({"You are drenched in a tropical downpour.\n",
    "You are drenched in a tropical downpour.\n",}),
}),


/* climate - tropic (climate == 3) */
({

}),

/* climate - desert (climate == 4) */
({
  ({"It is unpleasently warm and you feel the searing sand under your feet.\n",
    "A cool breeze blows some sand around.\n"}),
  ({"The air is dry and the sand shimers as you look toward the horizon.\n",
    "The cool desert night chills you to the bone.\n"}),
  ({"The sun is burning hot.\n",  "The desert seems surprizingly cool.\n"}),
  ({"A hot and dry wind blows flicking sand around your feet.\n",
    "The desert lies foreboding and still.\n"}),
  ({"A violent sandstorm beats at your exposed skin.\n",
    "Howling night winds whip the sand around you obscuring the moon.\n"}),
}),

/* climate - artic (climate == 5) */
({
  ({"The sunlight glitters on the snow.\n",
    "The moonlight glitters on the snow.\n"}),
  ({"A strong breeze is blowing.\n","A strong breeze is blowing.\n",}),
  ({"There are some snowclouds in the sky.\n",
    "There are some snowclouds in the twilight sky.\n",}),
  ({"It is snowing heavily.\n","It is snowing heavily.\n",}),
  ({"A wailing blizzard pummels you with snow.\n",
    "A wailing blizzard pummels you with snow.\n",}),
}),

/* climate - sea (climate == 6) */
({
  ({"It is very humid.\n", "It is a bit chilly.\n",}),
  ({"A heavy torrent issues from above making you wet and miserable.\n",
    "A heavy torrent issues from above making you wet and miserable.\n",}),
  ({"A violent storm errupts with fierce winds and enormous waves.\n",
    "A violent storm errupts with fierce winds and enormous waves.\n",}),
  ({"You are being soaked in a heavy ocean storm.\n",
    "You are being soaked in a heavy ocean storm.\n",}),
  ({"You are almost swept away in the howling winds of a viscious typhoon.\n",
 "You are almost swept away in the howling winds of a viscious typhoon.\n",}),
}),

});

  /* thus regardless of climate size we always get closet result */

  if(climate < 0) climate = 0;
  if(climate >= sizeof(all_weather)) climate = sizeof(all_weather)-1;
  if(weather < 0) weather = 0;
  if(weather >= sizeof(all_weather[climate])) 
    weather = sizeof(all_weather[climate]);

  return all_weather[climate][weather][query_night()];
}

varargs void change_weather(int climate_type) {
  int i;
  object *user;

  remove_call_out("change_weather");
  current_weather = next_weather;
  if(climate_type < 0 || climate_type > WEATHER_SIZE) climate_type = 0;
  next_weather = (climate_type) ? climate_type : random(WEATHER_SIZE);
  user = users();
  for(i = 0; i < sizeof(user); i++) {
    if(!user[i]->query_edit() && environment(user[i])) {
      environment(user[i])->weather(user[i], current_weather);
    }
  }
  call_out("change_weather",CHANGE_WEATHER_PERIOD);
}

int query_weather()      { return current_weather; }
int query_next_weather() { return next_weather; }


/*************************************************************************/
/* time - there is no correlation between real time and DAWN_HOUR */

#define DAY_PERIOD      10800 /* (3 hrs)  real seconds of 'pseudo' day   */
#define NIGHT_PERIOD    10800 /* (3 hrs)  real seconds of 'pseudo' night */
#define TWILIGHT_PERIOD  1800 /*(30 min.) real seconds of 'pseudo' dusk/dawn */
#define DAWN_HOUR           5 /* 5 O'Clock 'pseudo' mud time */


static void cycle_light() { 
  if(day_status == 1) light_adj = -1;
  if(day_status == -1) light_adj = 1;
  day_status = day_status + light_adj;
}

void change_time() { 
  int next_time;
  string str;
  int i;
  object *user;

  cycle_light();
  if(day_status == -1) {
    str = "It grows dark.\n";
    next_time = NIGHT_PERIOD;
  }
  else if(!day_status && light_adj == 1) {
    str = "Dawn breaks upon the horizon.\n";
    next_time = TWILIGHT_PERIOD;
  }
  else if(!day_status && light_adj == -1) {
    str = "The sun starts to sink beyond the horizon.\n";
    next_time = TWILIGHT_PERIOD;
  }
  else {
    str = "It grows light.\n";
    next_time = DAY_PERIOD;
    dawn_time = time();
    if(++day > 7) day = 1;
  }
  user = users();
  for(i = 0; i < sizeof(user); i++) {
    if(!user[i]->query_edit() && environment(user[i])) {
      tell_object(user[i],str);
    }
  }
  call_out("change_time", next_time);
}

string day() {
  string *week;

  week = ({ "", "Moonday", "Twyesdaeg", "Wodensdaeg","Thorsdagr",
            "Frigedaeg","Saeter-daeg","Solday", });
  return week[day];
}


string mud_time() {
  int mud_day, mud_hour, mud_minute;
  int hour, minute, pm;
  int t;
  string str;

  mud_day = DAY_PERIOD + NIGHT_PERIOD + 2 * TWILIGHT_PERIOD; /* sec per day */
  mud_hour = mud_day/24;     /* secs per hour */
  mud_minute = mud_hour/60;  /* secs per min  */
  t = time() - dawn_time;

  t %= mud_day;
  hour = t/mud_hour + DAWN_HOUR;
  hour %= 24;
  if(hour/12) pm = 1;
  hour %= 12;
  t %= mud_hour;
  minute = t/mud_minute;

  str = day() +"   "+hour+":"+((minute < 10) ? "0" : "") + minute;
  str += " "+((pm) ? "pm" : "am");

  return str;
}
  
status query_night() { return (day_status == -1); }
status query_day()   { return (day_status != -1); }
status query_dawn()  { return (!day_status && light_adj == 1);  }
status query_dusk()  { return (!day_status && light_adj == -1); }

int query_light_adjustment() { return light_adj; }

