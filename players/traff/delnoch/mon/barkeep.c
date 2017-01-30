/*  BARKEEP.C - Loads into TAVERN.C of Delnoch Town
    Changes as of 5-31-96:
    Color added, paths changed to fit new directory structure.
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object coins,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("barkeep");
  set_race("human");
  set_alias("ben");
  set_short(GRN+"Ben"+NORM+", the Barkeep");
  set_long(BOLD+
"Ben has a jovial look about him.  He has run this tavern for many\n"+
"years.  Though balding and portly, he looks like he can take care\n"+
"of himself when there is trouble.\n"+NORM);
  set_level(14);
  set_hp(210);
  set_al(250);
  set_wc(17+random(3));
  set_ac(10+random(3));
  set_chat_chance(15);
  set_a_chat_chance(25);
  load_chat("Ben says: Welcome friend.\n");
  load_chat("Ben rinses a mug in a pail of water and stacks it on the bar\n");
  load_chat("Ben winks at Jill.\n");
  load_chat("Ben asks: Any word from the mountains?\n");
  load_chat("Ben says: I hear the rebel force is growing.  The fools don't stand a chance!\n");
  load_chat("Ben wipes a spill from the bar top.\n");
  load_chat("Ben draws a beer, and hands it to Jill to deliver.\n");
  load_a_chat("Ben says: I've dealt with worse than the likes of you!\n");
  load_a_chat("Ben roars: Get out!  Get out of my tavern!\n");
  coins=clone_object("obj/money");
  coins->set_money(random(175)+700);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/delnoch/weps/mug.c");
  move_object(weapon,this_object());
  init_command("wield mug");
}
