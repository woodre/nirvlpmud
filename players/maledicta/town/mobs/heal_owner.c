#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("sandara");
set_alt_name("clerk_owner");
set_alias("clerk");
set_race("human");
set_short("Sandara the store clerk");
set_long(
"  Looking closely at this small petite woman, you see that she is\n"+
"dressed in a well-fitted white suit, a medical symbol on her left\n"+
"shoulder. She smiles at you with thin lips, which are tucked under\n"+
"a small perky nose. Her brown eyes are thoughtful and kind, and\n"+
"partially blocked by a stray strand of brown hair. She is happy\n"+
"to assist you.\n");

set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Sandara says: Welcome to my store traveler.\n");
  load_chat("The clerk straightens some medical supplies.\n");
  load_chat("Sandara says: If there is anything I can get you please let me know.\n");
  
set_a_chat_chance(15);
  load_a_chat("Sandara yells: HELP ME! HELP ME!!!\n");
  load_a_chat("The Clerk throws a jar of gauze at you!\n");
  load_a_chat("Sandara yells: Guards!!! Someone call the guards!\n");
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

