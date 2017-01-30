#include "std.h"

object maniac, body;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!maniac || !living(maniac)) {
  object scalpel;
    maniac = clone_object("obj/monster");
    call_other(maniac, "set_name", "maniac");
    call_other(maniac, "set_alias", "man");
    call_other(maniac, "set_level", 16);
    call_other(maniac, "set_hp", 390);
    call_other(maniac, "set_wc", 20);
    call_other(maniac, "set_ac", 14);
    call_other(maniac, "set_aggressive", 1);
    call_other(maniac, "set_al", -350);
    call_other(maniac, "set_short", "A homocidal maniac");
    call_other(maniac, "set_long",
      "A crazed man, wielding a scalpel, stands over the dead body of a\n" +
      "jogger as you approach.  He looks up, sees you and with a scream\n" +
      "attacks you!!!\n");
    move_object(maniac, this_object());
    scalpel = clone_object("obj/weapon");
    call_other(scalpel, "set_name", "scalpel");
    call_other(scalpel, "set_short", "A scalpel");
    call_other(scalpel, "set_long",
      "A surgical, steel scalpel, excessively sharp and very dangerous.\n");
    call_other(scalpel, "set_class", 16);
    call_other(scalpel, "set_value", 825);
    call_other(scalpel, "set_wieght", 1);
    transfer(scalpel, maniac);
  }
  body = present("corpse of jogger",this_object());
  if(!body) {
    object money;
    body = clone_object("obj/corpse");
    call_other(body,"set_name","jogger");
    move_object(body, this_object());
    money = clone_object("obj/money");
    call_other(money, "set_money", random(150));
    move_object(money, body);
    call_other(body,"reset");
  }
}
 
TWO_EXIT("players/aislinn/jog/jpath3", "east",
         "players/aislinn/jog/jpath5", "north",
         "The Jogging/Walking Path",
   "The path curves here, and there are large forsythia bushes growing\n" +
   "close to each side of the path, which make the path abit narrower.\n" +
    "    \n", 1)
