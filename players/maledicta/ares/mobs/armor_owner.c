#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("baltrek");
set_alt_name("armor_owner");
set_alias("armorer");
set_race("human");
set_short("Baltrek the Armorer");
set_long(
"  You stand before Baltrek, the cities leading armorer. He is\n"+
"a large bald man with numerous scars and burns along his huge\n"+
"forearms. He wears a leather apron over his dirty brown clothes.\n"+
"He seems ready to serve you.\n");
set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Baltrek straightens a set of plate armor.\n");
  load_chat("The store owner looks around and takes a mental inventory.\n");
  load_chat("Baltrek looks at you and waits patiently.\n");
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

