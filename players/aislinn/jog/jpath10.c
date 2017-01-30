#include "std.h"

object fisher;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!fisher || !living(fisher)) {
  object tackle, trout;
    fisher = clone_object("obj/monster");
    call_other(fisher, "set_name", "fisherman");
    call_other(fisher, "set_alias", "man");
    call_other(fisher, "set_level", 9);
    call_other(fisher, "set_hp", 180);
    call_other(fisher, "set_wc", 11);
    call_other(fisher, "set_ac", 7);
    call_other(fisher, "set_al", 200);
    call_other(fisher, "set_short", "A fisherman");
    call_other(fisher, "set_long",
      "A man, peacefully fishing at the stream.\n");
    move_object(fisher, this_object());
    tackle = clone_object("obj/treasure");
    call_other(tackle, "set_id", "tackle");
    call_other(tackle, "set_short", "Fishing tackle");
    call_other(tackle, "set_long",
      "An assortment of fishing poles, hooks, line, and a can of worms.\n");
    call_other(tackle, "set_value", 300);
    call_other(tackle, "set_weight", 3);
    transfer(tackle, fisher);
  }
}
 
TWO_EXIT("players/aislinn/jog/jpath9", "west",
         "players/aislinn/jog/jpath11", "east",
	 "Jogging Path",
   "The path passes rather close to a stream that runs through the\n" +
   "woods, and you wonder if there might possibly be any trout in\n" +
   "the stream....\n" +
    "    \n", 1)
