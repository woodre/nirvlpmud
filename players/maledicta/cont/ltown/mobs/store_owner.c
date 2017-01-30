#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("giltara");
set_alt_name("clerk_owner");
set_alias("merchant");
set_race("elf");
set_short("Giltara the Merchant");
set_long(
"  This is a tall elf merchant. He is dressed in a brown tunic and\n"+
"and wears a wide brimmed hat. His hair is blonde and his eyes are\n"+
"a deep brown. He seems ready to assist you.\n");
set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Giltara says: Welcome to my store traveler.\n");
  load_chat("The Merchant straightens some supplies.\n");
  
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

