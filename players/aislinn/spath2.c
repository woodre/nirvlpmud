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
    call_other(tball, "set_value",6);
    call_other(tball, "set_weight",0);
    move_object(tball,this_object());
  }
}
 
TWO_EXIT("players/aislinn/spath3", "west",
	 "players/aislinn/shady_path", "east",
	 "The Shady Path Continues",
    "The path continues past the fencing and into a deeper woods.  The\n" +
    "sounds of voices have faded and you now hear the chirping of birds\n" +
    "and the chattering of squirrels.  A small wooden sign is posted on\n" +
    "a tree, which reads:  Walking/Jogging Path Ahead.\n" +
    "    \n", 1)
