#include "std.h"
#include "living.h"
object goofy;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("players/mistress/child/disney/entrance","west",
         "players/mistress/child/disney/room1","east",
   "Goofy",
   "\nYou walk along a well-worn path and come to a small clearing.  Mud\n" +
   "splatters your feet.  It would be easy to slip and fall, but you are\n" +
   "very careful with your footing.\n",1)

extra_reset() {
  if(!goofy || !living(goofy)) {
    goofy = clone_object("obj/monster");
    call_other(goofy, "set_name", "goofy");
    call_other(goofy, "set_short", "Goofy");
    call_other(goofy, "set_long", "A goofy kind of guy.\n");
    call_other(goofy, "set_alias", "goof");
    call_other(goofy, "set_level", 3);
    call_other(goofy, "set_ac", 9);
    call_other(goofy, "set_wc", 5);
    call_other(goofy, "set_hp", 50);
    call_other(goofy, "set_al", 200);
    call_other(goofy, "add_money", 10);
  move_object(goofy, this_object()); }
  }
