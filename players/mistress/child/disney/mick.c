#include "std.h"
#include "living.h"
object mick, hoe;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/mistress/child/disney/yard","south",
   "Micky Mouse",
   "\nThe lawn has been neatly trimmed, but someone left the lawnmower\n" +
   "running quietly.  It is slowly making it's way towards the flower bed!\n" +
   
   "Oh dear!  Some whiskers are going to fly around here!\n",1)

extra_reset() {
  if(!mick || !living(mick)) {
   mick = clone_object("obj/monster");
    call_other(mick, "set_name", "Mickey Mouse");
    call_other(mick, "set_short", "Mickey Mouse");
    call_other(mick, "set_long", "The mouse who needs no intoduction...\n");
    call_other(mick, "set_alias", "mickey");
    call_other(mick, "set_alt_name", "mick");
    call_other(mick, "set_race", "mouse");
    call_other(mick, "set_level", 10);
    call_other(mick, "set_ac", 8);

    call_other(mick, "set_wc", 14);
    call_other(mick, "set_al", 1000);
    move_object(mick, this_object());
   hoe = clone_object("obj/weapon");
    call_other(hoe, "set_name", "hoe");
    call_other(hoe, "set_short", "A gardening hoe");
    call_other(hoe, "set_long", "The hoe has a lot of mud on it.\n");
    call_other(hoe, "set_class", 14);
    call_other(hoe, "set_weight", 3);
    call_other(hoe, "set_value", 450);
    transfer(hoe, mick);
   call_other(mick, "init_command", "wield hoe"); }
  }
