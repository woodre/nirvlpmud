/*  BARMAID.C - Loads into TAVERN.C of Delnoch Town.
    Changes as of 6-1-96:
    Color added, paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object coins,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("barmaid");
  set_race("human");
  set_alias("jill");
  set_short(BLU+"Jill"+NORM, the Barmaid");
  set_long(WHT+
"Jill has an impish air about her.  She has worked here for a long\n"+
"time, and has delt with many ruffians!  Rumor says that she is\n"+
"sweet on one of the Keep Guards.\n"+NORM);
  set_level(12);
  set_hp(180);
  set_al(random(500)-250);
  set_wc(15+random(3));
  set_ac(9+random(2));
  set_chat_chance(15);
  set_a_chat_chance(25);
  load_chat("Jill says: Welcome friend.\n");
  load_chat("Jill moves from table to table, collecting empty mugs.\n");
  load_chat("Jill winks at you, and smiles!.\n");
  load_chat("Jill asks: Are the Dragon troops really joining the rebels?\n");
  load_a_chat("Jill says: I've dealt with worse than the likes of you!\n");
  load_a_chat("Jill screams: You little pipsqueak!  I'll rip you head off and feed\n"+
"it to the pigs!\n");
  load_a_chat("Jill runs at you waving her tray over her head!\n");
  load_a_chat("Jill says: If anything happens to me Derrik will kill you!\n");
  load_a_chat("Jill taunts: What's the matter?  Couldn't you find any BOYS to play with?\n");
  coins=clone_object("obj/money");
  coins->set_money(random(200)+500);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/delnoch/weps/tray.c");
  move_object(weapon,this_object());
  init_command("wield tray");
}
