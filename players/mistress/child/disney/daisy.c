#include "std.h"
#include "living.h"
object daisy;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();


TWO_EXIT("players/mistress/child/disney/room1","south",
         "players/mistress/child/disney/pond","north",
   "Daisy Duck",
   "\nYou casually stroll towards the water...  The path has widened up\n" +
   "enough for you to even do a dance - if you want.  Then again,  you\n" +
   "might feel kind of silly, huh?\n",1)

extra_reset() {
  if(!daisy || !living(daisy)) {
    daisy = clone_object("obj/monster");
    call_other(daisy, "set_name", "Daisy Duck");
    call_other(daisy, "set_short", "Daisy Duck");
    call_other(daisy, "set_long", "She is Donald's girlfriend - or duckfriend?\n");
    call_other(daisy, "set_alias", "daisy");
    call_other(daisy, "set_race", "duck");
    call_other(daisy, "set_level", 2);
    call_other(daisy, "set_ac", 3);
    call_other(daisy, "set_wc", 6);
    call_other(daisy, "set_al", -100);
  move_object(daisy, this_object()); }
  }
