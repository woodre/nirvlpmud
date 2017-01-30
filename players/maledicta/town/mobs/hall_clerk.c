#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("bithrin");
set_alt_name("hall_clerk");
set_alias("clerk");
set_race("human");
set_short("Bithrin the records clerk");
set_long(
"  Before you stands Bithrin the records keeper. He is very\n"+
"thin and looks as though he has spent too many long hours\n"+
"at his job. He looks at you behind a pair of small glasses\n"+
"that sit at the end of his nose, his eyebrows raised in\n"+
"expectation.\n"); 

set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Bithrin says: Ummm...well....uh....\n");
  load_chat("The records clerk shuffles some papers.\n");
  load_chat("Bithrin says: Well...uh...did you need something?\n");
  
set_a_chat_chance(15);
  load_a_chat("Bithrin yells: Uh....HELP!!!!!!\n");
  load_a_chat("The Records Clerk throws a stack of papers at you!\n");
  load_a_chat("Bithrin yells for the Guards!\n");
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

