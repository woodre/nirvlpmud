#include "std.h"
#include "living.h"
object min, shoe;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("players/mistress/child/disney/hill","west",
         "players/mistress/child/disney/yard","north",
   "Minnie Mouse",
   "\nAs you approach the front of the cottage, you smell an apetizing\n" +
   "aroma of fresh apple pie.  Yum!  You glance around to see if you can\n" +
   "locate this delectable dessert, but you have no luck.\n",1)

extra_reset() {
  if(!min || !living(min)) {
    min = clone_object("obj/monster");
    call_other(min, "set_name", "Minnie Mouse");
    call_other(min, "set_short", "Minnie Mouse");
    call_other(min, "set_long", "Ain't she cute?\n");
    call_other(min, "set_race", "mouse");
    call_other(min, "set_alias", "minnie");
    call_other(min, "set_alt_name", "min");
    call_other(min, "set_level", 6);
    call_other(min, "set_ac", 5);
    call_other(min, "set_wc", 9);
    call_other(min, "set_hp", 100);
    call_other(min, "set_al", 100);
   move_object(min, this_object());
    shoe = clone_object("obj/armor");
    call_other(shoe, "set_name", "Minnie's shoes");
    call_other(shoe, "set_short", "A cartoon character's shoes");
    call_other(shoe, "set_long", "High heels?  Have fun!\n");
    call_other(shoe, "set_alias", "shoes");
    call_other(shoe, "set_type", "boots");
    call_other(shoe, "set_weight", 2);
    call_other(shoe, "set_ac", 2);
    call_other(shoe, "set_value", 50);
    transfer(shoe, min);
   call_other(min, "init_command", "wear shoes"); }
  }
