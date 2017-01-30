/* 
 * Forbin
 * Created:   2003.08.08
 * Last edit: 2003.08.29 -forbin
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * This object summons /players/forbin/dervish/NPC/albatross.c
 * to several different desert locations
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 */

#include "/players/forbin/define.h"
inherit "/obj/treasure";
#define TOU(x) if(environment()) tell_object(environment(), x);
#define TRU(x) if(environment() && environment(environment())) tell_room(environment(environment()), x, ({ environment() }));
#define USER environment()

static int summon;

id(str) { return str == "summon_dervish_albatross"; }

drop() { return 1; }

get() { return 1; }

reset(x) {
  if(x) return;
  if(!root())
  call_out("summon_albatross_Desert",4 + random(3));
}

init() {
  add_action("cmd_hook"); add_xverb("");
}

cmd_hook(string str) {
  if(this_player()->query_level() > 19) return 0;
  write("The ringing in your ears disorients you.  You stumble and fall as\n"+
        "you attempt do that.\n");
    return 1;
}

summon_albatross_Desert() {

  summon += 1;

  if(summon > 3) {
    TOU("With a thunderous flap of wings, the dark shadow lands before you.\n"+
        "Raising its head into the air and screeching, you see the creature\n"+
        "is a giant albatross.  It notices you, and is now staring menacingly.\n");
    TRU("With a thunderous noise, a giant albatross lands.  With a menacing\n"+
        "glare, it stares at "+environment(this_object())->query_name()+".\n");
    call_other("/players/forbin/dervish/NPC/albatross","???");
    move_object("/players/forbin/dervish/NPC/albatross.c",this_object());
    TOU("The ringing in your ears subsides\n");
    destruct(this_object());
      return;
  }
  else if(summon > 2) {
    TOU("Swooping high overhead, the dark shadow blots out the sun.  After\n"+
        "circling for a few moments, it dives towards you.\n");
    TRU("A dark shadow circles overhead, then dives steeply towards the ground.\n");
  }
  else if(summon > 1) {
    TOU("Whatever the shadow is, it moves swiftly towards you.  Higher\n"+
        "higher into the sky it climbs.\n");
    TRU("A dark shadow flies towards you from the south.\n");
  }
  else {
    TOU("You hear a screeching noise far out over the ocean.  You stare\n"+
        "intently at the horizon.  A dark shadow emerges from the south.\n");
    TRU("There is a screeching noise far out over the ocean.\n");
  }
  call_out("summon_albatross", 7 + random(4));
}