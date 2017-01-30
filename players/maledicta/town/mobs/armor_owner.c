#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("gerric");
set_alt_name("store_owner");
set_alias("owner");
set_race("human");
set_short("Gerric the Store Owner");
set_long(
"  Before you stands a large man dressed in plain clothes. A long beard\n"+
"dangles down to his belt and small twinkling eyes gaze out from bushey\n"+
"eyebrows. He seems cheery and in good spirits. You can tell that he is\n"+
"very proud of his shop.\n");

set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Gerric says: Good day travelers!\n");
  load_chat("Store owner polishes some armor.\n");
  load_chat("Store owner smiles happily.\n");
  load_chat("Gerric asks: Anything I can show you?\n");
set_a_chat_chance(15);
  load_a_chat("Gerric yells: HELP HELP!!!\n");
  load_a_chat("Store owner throws a wild swing at you!\n");
  load_a_chat("Gerric yells: I should have known!!!\n");
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

