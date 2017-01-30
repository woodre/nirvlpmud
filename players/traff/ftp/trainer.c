/*  TRAINER.C - Loads into room PANTRY.C of Delnoch Keep.  This monster
    carries the key that will open the door to the halfling pens.
    Changes as of 5-31-96:
    Color added, paths changed to fit new directory structure
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  object coins,weapon,key;
  ::reset(arg);
  if(arg) return;
  set_name("trainer");
  set_race("human");
  set_alias("man");
  set_short(CYN+"Halfling Trainer"+NORM);
  set_long(CYN+
"A large muscular man dressed in heavy leather.  You notice that\n"+
"the leather is covered with scratch and bite marks.\n"+NORM);
  set_level(18);
  set_hp(425+random(50));
  set_al(-800);
  set_wc(24+random(4));
  set_ac(13+random(4));
  set_chat_chance(2);
  set_a_chat_chance(10);
  load_chat("Trainer looks around the room like he is looking for food.\n");
  load_a_chat("Trainer says: Fools!  Only I can control the halflings!\n");
  set_chance(10);
  set_spell_mess1("Halfling Trainer glares at you with evil eyes.  You feel weaker.\n");
  set_spell_mess2("You feel an odd tingling as the Trainer smashes you with his sword\n");
  set_spell_dam(5);
  coins=clone_object("obj/money");
  coins->set_money(random(101)+750);
  move_object(coins,this_object());
  weapon = clone_object("/players/traff/delnoch/weps/halfsword.c");
  move_object(weapon,this_object());
  init_command("wield sword");
  key=clone_object("/players/traff/delnoch/obj/rustkey.c");
  move_object(key,this_object());
}
