/* storm_obj.c
 * Moved to the room when bards use their ability to create a thunderstorm
 * Updated from Saber's original code by Illarion in 6/2004
 */
 
#include "/players/guilds/bards/def.h"
#include "/players/guilds/bards/lib/ansi_pad.h"

int duration;
int start_time;
string *messages;
 
id(str) { 
  return str == "storm" || str=="thunderstorm" || str=="bard_storm_obj";
}

short() {
  return "A large and violent thunderstorm";
}

long() {
  write("Angry storm clouds fill the sky above, pouring down water and\n"+
        "bristling with angry-looking lightning bolts.  In addition to\n"+
        "the normal storm noises, there seems to be music emanating from\n"+
        "the clouds.\n");
}

reset(arg) {
  if(arg || root()) return;
  messages=  
  ({HIY+"Lightning"+NORM+" flashes across the sky!",
    "Thunder booms loudly overhead.",
    "The wind knifes past you, leaving a faint melody in your ears.",
    "Falling sheets of water slice by you.",
    "A light hail beats against you."
  });
}

void start_storm(int dur) {
  if(dur > duration-start_time)
    duration=dur;
  start_time=time();
  remove_call_out("storm");
  call_out("storm",10+random(20));
}

void do_message(string str) {
  if(!environment() || !str)
    return 0;
  tell_room(environment(),ansi_format(str));
}

void storm() {
  if(!environment() || time() > start_time+duration) {
    do_message("The storm clouds above swirl together into a single point, "+
               "then vanish.  A single clear note lingers in the air for "+
               "several seconds.");
    destruct(this_object());
    return;
  }
  do_message(messages[random(sizeof(messages))]);
  call_out("storm",10+random(20));
}
