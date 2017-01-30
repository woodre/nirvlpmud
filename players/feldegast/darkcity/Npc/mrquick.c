/* 
This was one of the Strangers that John killed on
the billboard sign.  "No more Mr. Quick?"
*/
#include "../def.h"   
inherit STRANGER;

reset(arg) {
  ::reset(arg);
  if(!present("knife")) {
    move_object(clone_object(PATH+"Wep/sdagger"),this_object());
    move_object(clone_object("/players/feldegast/equip/trenchcoat"),this_object());
   init_command("wear trenchcoat");
    init_command("wield knife");
  }
  if(arg) return;
  set_name("Mr. Quick");
  set_alt_name("mister");
  set_alias("quick");
  set_short("Mr. Quick");
  set_long(
    "Like all of his kind, Mr. Quick is unusually thin and\n"+
    "deathly pale.  He wears a dark hat and coat and carries\n"+
    "a wicked knife.  Mr. Quick has been assigned to bring in\n"+
    "a rogue human who resisted being implanted.\n"
  );
  set_gender("male");
  set_race("stranger");
  set_level(20);
  set_wc(30);
  set_ac(15); /* +2ac from armor */
  set_ac_bonus(2);
  set_hp(500);
  set_al(-1000);
  set_a_chat_chance(5);
  load_a_chat("Mr. Quick warps reality around him.\n");
  load_a_chat("Mr. Quick slashes with his knife, spilling "+RED+"blood"+NORM+" freely.\n");
  set_chance(15);
  set_spell_mess1(
    "\nMr. Quick projects a lance of "+HIM+"warped reality"+NORM+" at his foe.\n");
  set_spell_mess2(
    "\nMr. Quick projects a lance of "+HIM+"warped reality"+NORM+" at you.\n");
  set_spell_dam(40);
}
