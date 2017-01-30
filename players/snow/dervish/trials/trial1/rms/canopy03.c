/* 
 * Forbin
 * Created:   2003.09.08
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

int mfixed, mrandom;

reset(arg) {
  if(arg) return;
  short_desc = "A Forest Canopy";
  long_desc = GRN+HBGRN+
    "  You stand upon a wooden platform that encircles a massive tree.\n"+
    "Darkened wood has been fashioned into a railing that runs around \n"+
    "the circumference of the platform and provides protection from   \n"+
    "falling.  Two wooden bridges run to other platforms to the north \n"+
    "and east.                                                        \n"+
    "    There are two obvious exits: north, and east                 \n"+NORM;
  add_item(({"platform","wooden platform"}),
    "The wooden platform, built from dark wood, has been built around\n"+
    "a large tree");
  add_item("tree",
    "The tree, almost 10 meters in diameter, grows tall.  Its smooth\n"+
    "skinned bark is unmarked except for a long crack that runs across\n"+
    "it perpendicular to the ground");
  add_item("crack", 
    "A large crack is deeply grooved into the tree's bark");
  add_item(({"rail","railing"}),
    "A railing of weathered wood has been erected to keep people from\n"+
    "falling over the edge of the platform");
  add_item(({"bridge","bridges"}),
    "Rickety wooden bridges have been placed across to other platforms");  
  add_item("canopy",
    "The forest is alive around you, abuzz with motion and sound");
  set_chance(random(5));
    add_msg("Crickets chirp.");
    add_msg("Birds chatter in the treetops.");
    add_msg("An unfamiliar animal screeches somewhere off in the distance.");
  add_property("NT");
  set_light(1);
  no_exit_display = 1;
  add_exit(ROOT+"rms/canopy01.c","north");
  add_exit(ROOT+"rms/canopy05.c","east");
  add_exit_msg("north", "You follow the bridge from this tree platform to the next.\n",
		                "follows the bridge from this tree platform to the next.\n");
  add_exit_msg("east", "You follow the bridge from this tree platform to the next.\n",
		               "follows the bridge from this tree platform to the next.\n");
}

short() { if(random(2)) return GRN+"A Forest Canopy"+NORM;
          else return HIG+"A Forest Canopy"+NORM; }

init() {
  ::init();
  add_action("cmd_search","search");
}

cmd_search(string str) {
  int totalmoss;
  int x;
  object moss;
  if(!str || str != "crack") return 0;
  if(mfixed == 0 && mrandom == 0) {
    write("You carefully search the crack, but find nothing of interest.\n");
    say(this_player()->query_name()+" searches a crack in the tree.\n");
      return 1;
  }
  totalmoss = mfixed + random(1+mrandom));
  say(this_player()->query_name()+" searches a crack in the tree.\n");
  write("You carefully search the crack, and find some moss growing within.\n");
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
