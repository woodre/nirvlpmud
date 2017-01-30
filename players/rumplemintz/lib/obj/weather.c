/***************************************************************************/
/* MUD CLOCK
 *
 *
 * Don't clone this object
 *
 */

#include "/players/rumplemintz/lib/include/mudlib.h"
#include "/players/rumplemintz/lib/include/fn/i_to_th.h"
#include "/players/rumplemintz/lib/include/fn/i_to_str.h"



/***************************************************************************/
/* defines */

#define SAVE      "/players/rumplemintz/lib/ob_saves/time/time"

#define DAY_PERIOD        10800 /* can't be less than 720 seconds */
#define NIGHT_PERIOD      10800 /* can't be less than 720 seconds */
#define TWIGHLIGHT_PERIOD 10800 /* can't be less than 20 and no
                                          more than 3540                  */

#define SUNRISE_HOUR     5        /* hour for sun up                 */
#define SUNSET_HOUR    17       /* hour for sun down               */

#define WEATHER_SIZE            8        /* largest climate type          */
#define CHANGE_WEATHER_PERIOD   1350     /* every  was 1350 = 45 minutes  */

#ifdef DEBUG
#undef DEBUG
#define DEBUG find_player("rumplemintz")
#endif /* DEBUG */


/***************************************************************************/
/* variables */

int minute;
int hour;
int day;
int month;
int year;
int age;

int current_weather;
int next_weather;

status light_adj;
status day_status;

static int weather_timer;
static int clock_timer;
static int mud_day;
static int mud_hour;
static int mud_minute;

static string *mud_seasons;
static string *mud_months;
static string *mud_ages;



/***************************************************************************/
/* fn prototypes */


void msg(string str);

static void cycle_light();

int query_light_adjustment();

string query_mud_time();
string query_mud_date();

string query_all_weather(int climate, int weather);
varargs void change_weather(int climate_type);

/***************************************************************************/
/* reset and restore the time */

void reset(status arg) {
  if(arg) return;

  mud_day    = DAY_PERIOD + NIGHT_PERIOD + (2 * TWIGHLIGHT_PERIOD);
  mud_hour   = mud_day/24;     /* secs per hour */
  mud_minute = mud_hour/60;    /* secs per min  */

  restore_object(SAVE);

  /* if not minute, then make a start point for variables */
  /* set to just before dawn                              */
  if(!minute) {
    minute = 55;
    hour   = 4;
    day    = 1;
    month  = 1;
    year   = 175;    /* a few yrs after the history documents */
    age    = 1;

    day_status = -1; 
    light_adj = -1;
  }

  mud_months = ({
  "",
  "Gabriel", "Barchiel", "Malahidal",
      "Asmodel", "Ambriel", "Muriel",
      "Verchiel", "Hamaliel", "Uriel",
      "Barbiel", "Advanchiel", "Hanael",
  });


  mud_ages = ({
  "",
  "Restoration",
  "Age of Strength",
  "Age of Terror",
  "Age of Intuition",
  "Age of Guardianship",
  });

  mud_seasons = ({
  "Talvi, the season of Spring",
  "Casmaran, the season of Summer",
  "Ardarlel, the season of Autumn",
  "Farlas, the season of Winter",
  });


  set_heart_beat(1);
}

/***************************************************************************/
/* sets and queries */

string set_mud_time(int newHour, int newMinute) {
  if(newHour > 60 || newHour < 0) hour = 60;
  if(newMinute > 60 || newMinute < 0) minute = 60;

  hour = newHour;
  minute = newMinute;

  return query_mud_time();
}


string mud_time() { return query_mud_time(); }

string query_mud_time() {
  string str;

  str = ((hour < 10) ? "0" : "") + hour;
  str += ":"+((minute < 10) ? "0" : "") + minute;
  save_object(SAVE);
  return str;
}

string query_mud_date() {
  string str;

  str = capitalize(int_to_th(day))+" day of "+mud_months[month]+" ";
  str += "in the Year "+year+", being the Age of "+mud_ages[age];

  save_object(SAVE);
  return str;
}

string query_mud_season() {
  return mud_seasons[month/3];
}


status query_dawn()  { return (!day_status && light_adj == 1);  }
status query_dusk()  { return (!day_status && light_adj == -1); }

status query_night() { 
  return (hour < SUNRISE_HOUR || hour > SUNSET_HOUR) ? 1 : 0; 
}

status query_day()   { return !query_night();            }

status query_pm()    { return (hour < 12) ? 0 : 1;       }
status query_am()    { return (hour > 12) ? 0 : 1;       }

int query_hour()     { return hour;                      }
int query_minute()   { return minute;                    }

int query_light_adjustment() { return light_adj;         } 

int query_weather()      { return current_weather;       }
int query_next_weather() { return next_weather;          }



/***************************************************************************
 * Core of the clock *
 *
 * two seconds is a heart beat, so make the heart beat count x2 as fast
 * if you want time to go faster, better to decrease the DAY_PERIOD or
 * NIGHT_PERIOD defines above 
 */

void heart_beat() {
     
  weather_timer += 2; 
  clock_timer   += 2; 

  if(clock_timer > mud_minute) {
    clock_timer = 0;
    if(++minute >= 60) {
      minute = 0;
      if(++hour > 23) {
        hour = 0;
        if(++day > 29) {
          day = 1;
          save_object(SAVE);
          if(++month > 11) {
            month = 1;
            if(++year > 1000) {
              year = 1;
              age ++;
            }
          }
        }
      }
    }
  }

  /* sun rising and setting messages */
  if(hour > (SUNSET_HOUR-1) && day_status == 0) {
    day_status = -1; light_adj = -1;
    msg("Darkness sets in across the land as the sun vanishes "+
        "over the horizon\n");
  }
  else if(hour > (SUNSET_HOUR-1) && 
          minute > (TWIGHLIGHT_PERIOD/60) && 
          day_status == 1) {
    day_status = 0; light_adj = -1;
    msg("The sun starts to sink beyond the horizon.\n");
  }
  else if(hour > (SUNRISE_HOUR-1) && 
          minute > (TWIGHLIGHT_PERIOD/60) 
          && day_status == 0){
    day_status = 1; light_adj = 1;
    msg("The sun finishes rising and shines its light across the land.\n");
  }
  else if(hour > (SUNRISE_HOUR-1) &&
          hour < (SUNSET_HOUR-1) &&
          day_status == -1) {
    day_status = 0; light_adj = 1;
    msg("Dawn breaks over the horizon.\n");
  }

 
  /* weather is changed here */
  if(weather_timer > CHANGE_WEATHER_PERIOD) {
    change_weather(0);
    weather_timer = 0;
  }
}

/*************************************************************************/
/* weather - someone should extend the climate strings */

string query_all_weather(int climate, int weather) {
  mixed *all_weather;
  int day_night;

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
  ({"The humidity begins to get to you as your clothes begin to stick" +
    "to your sweaty skin.\n",
    "The night brings no relief as the humid air almost drips onto you.\n",}),
  ({"Mosquitoes plague you all day long, causing you to itch and scratch everywhere.\n",
    "Mosquitoe bites from the previous day cause your skin to become sore and red.\n",}),
  ({"Heavy jungle mist falls from the dense canopy above.\n",
    "Heavy jungle mist falls from the dark canopy above.\n",}),
  ({"The balmy conditions stifle you.\n",
    "The balmy conditions stifle you.\n",}),
  ({"The heat beats down mercilessly on you, clouding your thoughts in a haze.\n",
    "The cool of the night helps clear your thoughts some, offering a slight help.\n",}),
  ({"The unseen clouds hidden by the dense treetops begin to sprinkle lightly,\n"+
    "easing the heat a little.\n",
    "It begins to rain, the night sky is pitch black, shrouded by clouds and"+
    "treetops.\n",}),
  ({"The still air swelters around you, altering your perception of the surrounding" +
    "area.\n",
    "The humid and still air of the night causes your surroundings to become altered,\n"+
    "delusions of both sleep and heat.\n",}),
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
    weather = sizeof(all_weather[climate]) - 1;
  day_night = query_night();
  if(day_night < 0) day_night = 0;
  if(day_night >= sizeof(all_weather[climate][weather]))
    day_night = sizeof(all_weather[climate][weather]) - 1;
   
  return all_weather[climate][weather][query_night()];
}



varargs void change_weather(int climate_type) {
  int i;
  object *user;

  current_weather = next_weather;

  if(climate_type < 0 || climate_type > WEATHER_SIZE) climate_type = 0;

  next_weather = (climate_type) ? climate_type : random(WEATHER_SIZE);

  user = users();

  for(i = 0; i < sizeof(user); i++) {
    if(!user[i]->query_edit() && environment(user[i])) {
      environment(user[i])->show_weather(user[i]);
    }
  }
}


void msg(string str) {
  object *user;
  int i;

  user = users();
  for(i = 0; i < sizeof(user); i++) {
    if(!user[i]->query_edit() && environment(user[i])) {
      tell_object(user[i],str);
    }
  }   
}




