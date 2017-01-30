#include "std.h"

int value, cost, strength, heal;
string name, short_desc, mess;
 
object gardner;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!gardner || !living(gardner)) {
    object rose, potion, bottle;
      gardner = clone_object("obj/monster");
      call_other(gardner, "set_name", "gardener");
      call_other(gardner, "set_alias", "man");
      call_other(gardner, "set_level", 12);
      call_other(gardner, "set_hp", 300);
      call_other(gardner, "set_wc", 11);
      call_other(gardner, "set_ac", 9);
      call_other(gardner, "set_wimpy");
      call_other(gardner, "set_al", 250);
      call_other(gardner, "set_short", "A Gardener");
      call_other(gardner, "set_long",
        "A gardener tending the roses.....\n");
      move_object(gardner, this_object());
      rose = clone_object("obj/armor");
      call_other(rose, "set_id", "rose");
      call_other(rose, "set_alias", "flower");
      call_other(rose, "set_short", "A perfect rose....");
      call_other(rose, "set_value", 125);
      call_other(rose, "set_weight", 1);
      call_other(rose, "set_ac", 0);
      call_other(rose, "set_type", "rose");
      transfer(rose, gardner);
      bottle = clone_object("obj/drink");
      if(!call_other(bottle, "set_value", "potion" + "#" + 
        "A bottle of Gatorade" + "#" + "Gatorade *is* Thirst Aid!!!" +
        "#" + 75 + "#" + 300 + "#" + 0)) {
      return 1;
      }
      transfer(bottle, gardner);
  }
}
 
TWO_EXIT("players/aislinn/jog/jpath5", "south",
         "players/aislinn/jog/jpath7", "north",
	 "Jogging Path",
    "The path continues straight for abit.  A small rose garden can\n" +
    "be seen off to the west, and the fragrance of the roses is\n" +
    "intoxicating.  A grassy, cleared area is to the east, where\n" +
    "joggers can sit and relax in the sun.\n" +
    "    \n", 1)
