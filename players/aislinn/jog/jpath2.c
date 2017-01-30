#include "std.h"

object jogger;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!jogger || !living(jogger)) {
  object money;
    jogger = clone_object("obj/monster");
    call_other(jogger, "set_name", "jogger");
    call_other(jogger, "set_alias", "man");
    call_other(jogger, "set_level", 2);
    call_other(jogger, "set_hp", 55);
    call_other(jogger, "set_wc", 3);
    call_other(jogger, "set_ac", 5);
    call_other(jogger, "set_al", 100);
    call_other(jogger, "set_short", "An exhausted jogger");
    call_other(jogger, "set_long",  
      "A jogger sits on the bench, gasping for breath, red-faced and\n" +
      "sweating heavily....\n");
    move_object(jogger, this_object());
    money = clone_object("obj/money");
    call_other(money, "set_money", random(200));
    move_object(money, jogger);
  }
}
 
TWO_EXIT("players/aislinn/jog/jpath3", "south",
         "players/aislinn/jog/jpath1", "north",
         "The Jogging Path",
   "The path is approximately 5 feet wide and extremely comfortable to\n" +
   "run or walk upon.  The area is cool, with a slight breeze making \n" +
   "the conditions almost ideal to run in.  There is a bench off to \n" +
   "to the side for those who wish to rest.....\n" +
    "    \n", 1)
