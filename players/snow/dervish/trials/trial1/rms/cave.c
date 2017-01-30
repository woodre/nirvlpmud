/* 
 * Forbin
 * Created:   2003.08.25
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

reset(arg) {
  if(arg) return;
  short_desc = HIK+"A dark cave"+NORM;
  long_desc = WHT+REV+
    "  The cave seems to take in light and absorb it, keeping the area\n"+
    "in a dim darkness.  Deeper into the cave, light pours in from    \n"+
    "outside, marking a way out.  The ceiling, floor, and walls are   \n"+
    "cracked and pitted from the many roots growing through them.  The\n"+
    "air is cold and damp, and everything around is covered with a    \n"+
    "slick, wet ooze.                                                 \n"
    "    There is one obvious exit: out                               \n"+NORM;
  add_item(({"cave","area"}),
    "The cave is a cold, damp, dark place");
  add_item("light",
    "Far ahead you can see outside light filtering in");
  add_item("ceiling",
    "The ceiling is marked by cracks and pits.  A large hole lies in\n"+
    "the center of it.  If you could reach it, you may be able to\n"+
    "climb out of here");
  add_item("floor",
    "The floor is an amalgam of dirt, rocks, and stones");
  add_item(({"dirt","rock","rocks","stone","stones"}),
    "Rocks and stones lie scattered about the dirt floor of the cave");
  add_item(({"wall","walls"}),
    "The walls are full of cracks, holes and pitted places");
  add_item(({"hole","holes","crack","cracks","pitted place","pitted places"}),
    "The walls are filled with these cracks and hole, some of which\n"+
    "appear to be unnatural handholds.  You may be able to climb out\n"+
    "of the cave using these");
  add_item(({"root","roots"}),
    "Roots have grown through the ceiling, floor, and walls causing\n"+
    "cracks and holes to be formed");
  add_item("ooze",
    "Everything is covered in a strange green ooze");
  add_listen("main", 
    "You hear water rushing far off into the distance.\n");
  add_listen("water", 
    "You hear running water in the direction of the light ahead.\n");
  add_touch("walls",
    "You hand becomes slippery as you touch the strange ooze.\n");
  add_touch("ooze",
    "You hand becomes slippery as you touch the strange ooze.\n");
  add_taste("ooze",
    "You take a bit of the ooze and eat it.  It slides easily down\n"+
    "your throat with a sour aftertaste.\n");
  no_exit_display = 1;
  add_exit(ROOT+"rms/paradise01.c","out");
}

short() { return HIK+"A dark cave"+NORM;; }

init() {
  ::init();
  add_action("cmd_climb","climb");
}

cmd_climb() {
  write("You study the cracks and holes, then carefully use them as\n"+
        "handholds to climb up out of the cave.\n");
  say(this_player()->query_name()+" climbs through a hole in the ceiling.\n");
  move_object(this_player(),ROOT+"rms/entrance.c");
  command("look",this_player());
  say(this_player()->query_name()+" climbs out of the hole.\n");
    return 1; 
}
