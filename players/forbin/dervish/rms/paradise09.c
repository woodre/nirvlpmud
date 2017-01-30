/* 
 * Forbin
 * Created:   2003.09.11
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

reset(arg) {
  if(arg) return;
  short_desc = GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM;
  long_desc = 
    "  A stream runs through the forest from the northwest to the\n"+
    "east.  The banks on each side of the stream are gently sloping\n"+
    "towards the water, and short trampled grass grows in patches\n"+
    "along the stream's edge.  The surrounding forest is full of trees\n"+
    "and vines.\n"+
    "    There are two obvious exits: east, and northwest\n";
  add_item(({"stream","water"}),
    "The small stream is slight in depth, but is fairly wide");
  add_item(({"forest","tree","trees"}),
    "The forest's trees, many of which are full with tangles of vines,\n"+
    "stretch skyward, cloaking most of this area in shade");
  add_item(({"bank","banks","edge"}),
    "The dark clay bank is covered in most places with grass");
  add_item("grass",
    "The surrounding grass looks well traveled");
  add_item(({"vine","vines"}),
    "The trees are choked with thick vines.  Several have knots tied\n"+
    "along them.  You might be able to climb one");
  add_listen("main",
    "The streams bubbles and gurgles on its way east.\n");
  add_smell("main",
    "You smell a light scent of salt on the air.\n");
  add_taste("stream",
    "The water is cool and refreshing.\n");
  add_taste("water",
    "The water is cool and refreshing.\n");
  set_light(1);
  no_exit_display = 1;
  add_exit(ROOT+"rms/paradise10.c","east");
  add_exit(ROOT+"rms/paradise08.c","northwest");
  add_exit(ROOT+"rms/canopy01.c","up");
  add_exit_msg("east", "You head off into the jungle.\n",
		               "heads off into the jungle.\n");
  add_exit_msg("northwest", "You head off into the jungle.\n",
		                    "heads off into the jungle.\n");
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_climb","climb");
  add_action("cmd_block","up");
}

cmd_climb(string str) {
  if(!str || (str != "vine" && str != "vines")) { 
    notify_fail("Climb what?\n"); 
      return 0; 
  }
  write("You give one of the vines a tug to test its strength, then take\n"+
        "off climbing into the canopy above.\n");
  say(this_player()->query_name()+" climbs a vine into the canopy above.\n");
  move_object(this_player(),ROOT+"rms/canopy01.c");
  command("look",this_player());
  say(this_player()->query_name()+" comes climbing up a vine.\n");
    return 1; 
}

cmd_block() { write("What?\n"); return 1; }
