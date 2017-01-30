/*  COOKHELP.C - Loads into KITCHEN.C of Delnoch Keep.
    Changes as of 5-31-96:
    Color added, paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object coins,food;
  ::reset(arg);
  if(arg) return;
  set_name("cook");
  set_race("human");
  set_alias("helper");
  set_short(HIC+"Cook's helper"+NORM);
  set_long(HIC+
"This guy looks like he could use a good meal.  A tall skinny dude\n"+
"he almost looks comical in his white hat and apron.\n"+NORM);
  set_level(16);
  set_hp(350+random(75));
  set_al(650);
  set_wc(21+random(3));
  set_ac(12+random(3));
  set_chat_chance(15);
  set_a_chat_chance(25);
  load_chat("A girl enters and gets some tea, then heads back to the hall.\n");
  load_chat("The helper stirs a pot of soup.\n");
  load_chat("The helper goes to the scullery and returns with some peeled potatos.\n");
  load_chat("Helper says: I miss the good old days.\n");
  load_a_chat("Helper screams: Be careful!  You'll ruin my dinner!\n");
  load_a_chat("Helper runs around the stove trying to avoid you.\n");
  coins=clone_object("obj/money");
  coins->set_money(random(175)+750);
  move_object(coins,this_object());
  food = clone_object("/players/traff/delnoch/obj/roll.c");
  move_object(food,this_object());
}
