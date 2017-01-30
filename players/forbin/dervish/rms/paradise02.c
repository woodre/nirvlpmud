/* 
 * Forbin
 * Created:   2003.08.28
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

int mfixed, mrandom;

reset(arg) {
  if(arg) return;
  short_desc = GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM;
  long_desc = WHT+REV+
    "  The is a small cave that looks carved by running water.  The   \n"+
    "walls are a smooth, light gray; they create a perfectly round    \n"+
    "tunnel where the walls die into the curved floor and ceiling with\n"+
    "any marked transition.  A dirt trail leads up through a hole in  \n"+
    "one corner of the cave, while a beautiful waterfall creates a    \n"+
    "falling wall of water opposite the trail.  The waterfall shimmers\n"+
    "as light filters in.                                             \n"+
    "    There is one obvious exit: trail                             \n"+NORM;
  add_item(({"cave","tunnel"}),
    "A round cave with a trail at one end and a waterfall at the other");
  add_item(({"wall","walls","floor"}),
    "The walls, floor, and ceiling all merge together forming a tunnel");
  add_item(({"trail","dirt trail","hole","corner"}),
    "A brown, dirty trail leads up out the back of the cave");
  add_item(({"water","waterfall","fall"}),
    "A wall of water cascades over the opening of the cave.  One might\n"+
    "be able to pass through it if they don't mind getting wet");
  add_listen("main", 
    "The roar of the falls is deafening.\n");
  set_light(1);
  no_exit_display = 1;
  add_exit(ROOT+"rms/paradise01.c","trail");
  add_exit_msg("trail", "You follow the trail up the cliffs.\n",
                        "follows the trail up the cliffs.\n");
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_pass","pass");
  add_action("cmd_search","search");
}

cmd_pass(string str) {
  object wetme;
  if(!str || (str != "water" && str != "waterfall" && 
    str != "through water" && str != "through waterfall")) { 
    notify_fail("Pass through what?\n"); 
      return 0; 
  }
  write("You walk into the waterfall and out the other side - SOAKED!\n");
  say(this_player()->query_name()+" walks into the falling water.\n");
  move_object(this_player(),ROOT+"rms/paradise03.c");
  command("look",this_player());
  say(this_player()->query_name()+" emerges from the waterfall.\n");
  if(!present("waterfall_wet_object",this_player())) {
    wetme = clone_object(ROOT+"obj/allwet.c"); 
    move_object(wetme,this_player());
  }
  else { 
    destruct(present("waterfall_wet_object",this_player()));
    wetme = clone_object(ROOT+"obj/allwet.c"); 
    move_object(wetme,this_player());
  }
    return 1; 
}

cmd_search(string str) {
  int totalmoss;
  int x;
  object moss;
  if(!str || str != "cave") return 0;
  if(mfixed == 0 && mrandom == 0) {
    write("You carefully search the cave, but find nothing of interest.\n");
    say(this_player()->query_name()+" searches the cave.\n");
      return 1;
  }
  totalmoss = mfixed + random(1+mrandom));
  say(this_player()->query_name()+" searches the cave.\n");
  write("You carefully search the cave, and find some moss growing on the walls.\n");
  for(x = 0; x < totalmoss; x++) {
    moss = clone_object(ROOT+"obj/moss.c");
    move_object(moss,this_player());
  }
  mfixed = 0;
  mrandom = 0;
  return 1; 
}

/*
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~= 
 * initializing functions for setting up the moss search - these
 * are called from /players/snow/dervish/trials/trial1/rms/entrance.c
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 */
set_moss_fixed(int x)  { mfixed = x; }
add_moss_fixed(int x)  { mfixed += x; }
query_moss_fixed()     { return mfixed; }
set_moss_random(int x) { mrandom = x; }
add_moss_random(int x) { mrandom += x; }
query_moss_random()    { return mrandom; }

