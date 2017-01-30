/* 
 * Forbin
 * Created:   2003.09.11
 * Last edit: 2003.10.30 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

int mfixed, mrandom;

reset(arg) {
  if(arg) return;
  short_desc = GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM;
  long_desc = 
    "  Carving its path though the jungle, a small stream flows from\n"+
    "the north and gushes to the southwest after forming a small set\n"+
    "of rapids on some rocks below.  The bank here is steep, whittled\n"+
    "away over time by quick waterflow.  Trees, bushes, and vines\n"+
    "closely crowd the area, creeping extremely close to the bank\n"+
    "which leaves little walking room.\n";
  add_item(({"forest","tree","trees","jungle"}),
    "Tall trees thick grow high on each bank of the stream");
  add_item("stream",
    "The stream's water looks cold and refreshing");
  add_item("rapids",
    "The water churns and splashes creating a white froth");
  add_item(({"rock","rocks"}),
    "Rushing against the rocks, the stream makes dangerous rapids");
  add_item("bank",
    "The bank, a dark red clay, steeply dives into the stream.  You\n"+
    "noticed something green growning near the bank's edge");
  add_item(({"bush","bushes"}),
    "Several different types of undergrowth grow unchecked");
  add_item(({"vine","vines"}),
    "The vines clog the forest and drape from tree to tree");
  set_chance(random(5));
    add_msg("Water splashes up from the stream.");
    add_msg("The water crashes loudly on the rapids.");
  set_light(1);
  add_exit(ROOT+"rms/paradise04.c","north");
  add_exit(ROOT+"rms/paradise09.c","southwest");
  add_exit_msg("north", "You head off into the jungle.\n",
		                "heads off into the jungle.\n");
  add_exit_msg("southwest", "You head off into the jungle.\n",
		                    "heads off into the jungle.\n");
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_search","search");
}

cmd_search(string str) {
  int totalmoss;
  int x;
  object moss;
  if(!str || str != "bank") return 0;
  if(mfixed == 0 && mrandom == 0) {
    write("You carefully search the bank, but find nothing of interest.\n");
    say(this_player()->query_name()+" searches the stream's bank.\n");
      return 1;
  }
  totalmoss = mfixed + random(1+mrandom));
  say(this_player()->query_name()+" searches the stream's bank.\n");
  write("You carefully search the bank, and find some moss growing along it.\n");
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