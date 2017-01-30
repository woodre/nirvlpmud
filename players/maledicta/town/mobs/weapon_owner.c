#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("samuel");
set_alt_name("weapon_owner");
set_alias("weaponsmith");
set_race("human");
set_short("Samuel the Weaponsmith");
set_long(
"  Before you stands a tall lanky man, with short black hair.  He wears\n"+
"a grey jumpsuit, its clothe burned in some places. He looks at you with\n"+
"a smile, and continues working around the shop.\n");
set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Samuel polishes a sword.\n");
  load_chat("The store owner cleans a shelf.\n");
  load_chat("Samuel looks at you and smiles.\n");
set_a_chat_chance(15);
  load_a_chat("Samuel yells: HELP HELP!!!\n");
  load_a_chat("The weaponsmith throws a wild swing at you!\n");
  load_a_chat("Samuel yells: GUARDS!!!!\n");
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

