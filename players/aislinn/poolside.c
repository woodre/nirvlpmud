#include "std.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET set_dragon();
 
set_dragon() {
  object toy;
  toy = present("dragon",this_object());
  if(!toy) {
    toy = clone_object("obj/treasure");
    call_other(toy,"set_name","inflatable dragon");
    call_other(toy,"set_alias","dragon");
    call_other(toy,"set_short","An inflatable dragon");
    call_other(toy,"set_long",
      "An inflatable toy dragon, used in the water for play and to help\n" +
      "children stay afloat.\n", 1);
    call_other(toy,"set_value",1);
    call_other(toy,"set_weight",2);
    move_object(toy,this_object());
  }
}
 
FOUR_EXIT("players/aislinn/2pool","west",
	   "players/aislinn/tan_area","north",
	   "players/aislinn/change_area","south",
	   "players/aislinn/pool_shallow","east",
	   "Poolside at the Shallow End",
    "The cement path widens out here and you are now standing about a foot\n" +
    "from the edge of the pool itself.  Looking around, you see this is \n" +
    "the shallow end of the pool by reading the depth markers.  A few kids\n" +
    "are playing tag and an elderly woman is just sitting in the water,\n" +
    "relaxing in the sun.....\n" +
     "     \n", 1)
