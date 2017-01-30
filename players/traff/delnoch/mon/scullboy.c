/*  SCULLBOY.C - Loads into SCULLERY.C of Delnoch Keep.
    Changes as of 5-29-96:
    Color added, paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object coins,food;
  ::reset(arg);
  if(arg) return;
  set_name("boy");
  set_race("human");
  set_alias("helper");
  set_short(BLU+"Scullery boy"+NORM);
  set_long(YEL+
"A teenager from the village.  You wonder if what he eats isn't\n"+
"worth more than the meager sallery he earns here.  In any case\n"+
"he appears to be healthy, and at least somewhat industrious.\n"+NORM);
  set_level(16);
  set_hp(350+random(75));
  set_al(650);
  set_wc(21+random(3));
  set_ac(12+random(3));
  set_chat_chance(15);
  set_a_chat_chance(25);
  load_chat("A kitchen helper comes in and collects the peeled potatos.\n");
  load_chat("The boy looks at the pile of un-peeled potatos and sighs.\n");
  load_chat("The boy nibbles at a dinner roll.\n");
  load_chat("Boy mumbles: At least on the farm I was out in the fresh air.\n");
  load_a_chat("The boy throws a potato at you!\n");
  load_a_chat("Boy says: With all the evil around here, you have to pick on me!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(175)+750);
  move_object(coins,this_object());
  food = clone_object("/players/traff/delnoch/obj/roll.c");
  move_object(food,this_object());
}
