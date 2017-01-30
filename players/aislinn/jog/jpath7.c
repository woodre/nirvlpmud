#include "std.h"

object mower;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!mower || !living(mower)) {
    mower = clone_object("obj/monster");
    call_other(mower, "set_name", "mower");
    call_other(mower, "set_level", 15);
    call_other(mower, "set_hp", 300);
    call_other(mower, "set_wc", 17);
    call_other(mower, "set_ac", 13);
    call_other(mower, "set_al", 0);
    call_other(mower, "set_short", "A push mower");
    call_other(mower, "set_long",
      "An old-fashioned, push-type lawnmower....\n");
    move_object(mower, this_object());
  }
}
 
TWO_EXIT("players/aislinn/jog/jpath6", "south",
         "players/aislinn/jog/jpath8", "west",
	 "Jogging Path",
   "There is a well-manicured lawn to the west, with the grass looking\n" +
   "well-tended and a glorious shade of green.....\n" +
    "    \n", 1)
