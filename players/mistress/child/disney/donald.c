#include "std.h"
#include "living.h"
object donald, feet;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/mistress/child/disney/pond","south",
   "Donald Duck",
   "\nThe grass hear has been trampled down.  It almost looks like\n" +
   "someone has been dancing....  Maybe the disco duck?  Silly, huh?\n",1)

extra_reset() {
  if(!donald || !living(donald)) {
    donald = clone_object("obj/monster");
    call_other(donald, "set_name", "Donald Duck");
    call_other(donald, "set_short", "Donald Duck");
    call_other(donald, "set_long", "The original disco duck.\n");
    call_other(donald, "set_race", "duck");
    call_other(donald, "set_alt_name", "donald");
    call_other(donald, "set_level", 7);
    call_other(donald, "set_ac", 8);
    call_other(donald, "set_wc", 8);
    call_other(donald, "set_hp", 200);
    call_other(donald, "set_al", -500);
  move_object(donald, this_object()); }
  }
