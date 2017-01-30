/* 
This guy's name was mentioned briefly as one
of the three Strangers with Mr. Hand.  He's the
one who got squashed on the fire escape.
*/
#include "../def.h"   
inherit STRANGER;

reset(arg) {
  ::reset(arg);
  if(!present("knife")) {
    move_object(clone_object(PATH+"Wep/sdagger"));
    move_object(clone_object("/players/feldegast/equip/trenchcoat"),this_object());
   init_command("wear trenchcoat");
    init_command("wield knife");
  }
  if(arg) return;
  set_name("Mr. Rain");
  set_alt_name("mister");
  set_alias("rain");
  set_short("Mr. Rain");
  set_long(
    "Like all of his kind, Mr. Rain is unusually thin and\n"+
    "deathly pale.  He wears a dark hat and coat and carries\n"+
    "a wicked knife.  Mr. Rain has been assigned to bring in\n"+
    "a rogue human who is said to be able to Tune.\n"
  );
  set_gender("male");
  set_race("stranger");
  set_level(20);
  set_wc(30);
  set_ac(15); /* +ac2 armor */
  set_ac_bonus(2);
  set_hp(550);
  set_al(-1000);
  set_chat_chance(5);
  set_a_chat_chance(0);
  load_a_chat("Mr. Rain warps reality around him.");
  load_a_chat("Mr. Rain slashes with his knife, spilling "+RED+"blood"+NORM+" freely.\n");
  set_chance(25);
  set_spell_mess1(
    "\nMr. Rain projects a lance of "+HIM+"warped reality"+NORM+" at his foe.\n");
  set_spell_mess2(
    "\nMr. Rain projects a lance of "+HIM+"warped reality"+NORM+" at you.\n");
  set_spell_dam(30);
}
