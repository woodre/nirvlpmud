#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("darbo");
set_alt_name("weapon_owner");
set_alias("weaponsmith");
set_race("human");
set_short("Darbo the Weaponsmith");
set_long(
"  This is Darbo, the weaponsmith of the New Ares Weapon Shop. He\n"+
"is of average height and wears dark clothing.  His hair is brown\n"+
"and hangs in a pony-tail over his right shoulder.  He seems ready\n"+
"to serve you.\n");
set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Darbo polishes a sword.\n");
  load_chat("The store owner cleans a shelf.\n");
  load_chat("Darbo glances at you.\n");
set_a_chat_chance(15);
  load_a_chat("Darbo yells: HELP HELP!!!\n");
  load_a_chat("The weaponsmith throws a wild swing at you!\n");
  load_a_chat("Darbo yells: GUARDS!!!!\n");
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

