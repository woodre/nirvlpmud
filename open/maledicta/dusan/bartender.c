#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("stevil");
set_alt_name("bar_owner");
set_alias("owner");
set_race("human");
set_short("Stevil the bartender");
set_long(
"  This is the owner and operator of the finest tavern in Derellia. He stands\n"+
"at about average height, and is slightly overweight. His white apron is\n"+
"slightly stained from the cleaning and constant work he does. Stevil seems\n"+
"to be a very cheerful and polite man.\n");
set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Stevil says: Please, come in and let me get you something!\n");
  load_chat("The bartender polishes a glass.\n");
  load_chat("The bartender serves some customers delicious looking food.\n");
set_a_chat_chance(15);
  load_a_chat("Stevil yells: HELP HELP!!!\n");
  load_a_chat("The bartender throws a wild swing at you!\n");
  load_a_chat("Stevil yells: GUARDS!!!!\n");
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

