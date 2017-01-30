#include "/players/jareel/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("hermit");
set_alias("man");
set_race("human");
set_short(BOLD+BLK+"Hermit"+NORM);
set_long(
  "You see a psychotic delusional old man standing\n"+
  "with his back to the sun.  His frenzied eyes dazzle\n"+
  "from beneath his cowl, and his loose skin glows eerily.\n");

set_level(10);
set_hp(150);
set_al(0);
set_wc(14);
set_ac(8);
set_heal(1,1);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("Hermit says: The sun cult is over running this area beware of the light.\n");
  load_chat("Hermit says: The light burns.\n");
  load_chat("Hermit says: Beware they are all around.\n");
  load_chat("Hermit says: Stay away from the temple.\n");
  load_chat("Hermit says: Darkness is hidden to the east.\n");
  load_chat("Hermit says: You may find an ally in the wind.\n");
  load_chat("The hermit scratches skin from his arm.\n");
  load_chat("The hermit rocks back and forth.\n");
  load_chat("Hermit say: Grundga sunka unden?\n");
gold = clone_object("obj/money");
gold->set_money(400);
move_object(gold,this_object());
}
