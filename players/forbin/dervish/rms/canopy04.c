/* 
 * Forbin
 * Created:   2003.09.08
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

int mfixed, mrandom;

reset(arg) {
  if(arg) return;
  short_desc = "A Forest Canopy";
  long_desc = GRN+HBGRN+
    "  You stand upon a wooden platform that encircles a massive tree.\n"+
    "Darkened wood has been fashioned into a railing that runs around \n"+
    "the circumference of the platform and provides protection from   \n"+
    "falling.  Two wooden bridges run to other platforms to the south \n"+
    "and west.                                                        \n"+
    "    There are two obvious exits: south, and west                 \n"+NORM;
  add_item(({"platform","wooden platform"}),
    "The wooden platform, built from dark wood, has been built around\n"+
    "a large tree");
  add_item("tree",
    "The tree, almost 10 meters in diameter, grows tall.");
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
  add_exit(ROOT+"rms/canopy05.c","south");
  add_exit(ROOT+"rms/canopy01.c","west");
  add_exit_msg("south", "You follow the bridge from this tree platform to the next.\n",
		                "follows the bridge from this tree platform to the next.\n");
  add_exit_msg("west", "You follow the bridge from this tree platform to the next.\n",
		               "follows the bridge from this tree platform to the next.\n");
}

short() { if(random(2)) return GRN+"A Forest Canopy"+NORM;
          else return HIG+"A Forest Canopy"+NORM; }

init() {
  ::init();
}


