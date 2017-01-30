#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  object tball;
  tball = present("ball",this_object());
  if(!tball) {
    tball = clone_object("obj/treasure");
    call_other(tball, "set_name","tennis ball");
    call_other(tball, "set_alias","ball");
    call_other(tball, "set_short","A tennis ball");
    call_other(tball, "set_long",
      "A worn tennis ball, which looks like it was left out in the rain.\n");
    call_other(tball, "set_value",2);
    call_other(tball, "set_weight",0);
    move_object(tball,this_object());
  }
}
 
TWO_EXIT("players/aislinn/spath2", "west",
	 "players/aislinn/2tennis", "east",
	 "A Shady Path past the Tennis Courts",
    "You are walking along a path that runs next to the fencing which\n" +
    "surrounds the tennis courts.  This is just a dirt path, cut through\n" +
    "the woods.  It is very peaceful and serene here, the only sounds \n" +
    "being the rustling of leaves and the occasional muffled voice from\n" +
    "someone playing somewhere.\n" +
    "    \n", 1)
