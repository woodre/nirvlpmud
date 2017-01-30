/* 
What's Riff-raff doing in this pic? 
This is the Stranger who gets implanted with John's
false memories in order to track him down.
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
  set_name("Mr. Hand");
  set_alt_name("mister");
  set_alias("hand");
  set_short("Mr. Hand");
  set_long(
"Like all of his kind, Mr. Hand is unusually thin and\n"+
"deathly pale.  He wears a hat and coat and carries a\n"+
"wicked knife.  Mr. Hand volunteered to receive the\n"+
"memories of John Murdoch in order to track him down.\n"
);
  set_gender("male");
  set_race("stranger");
  set_level(20);
  set_wc(31);
  set_ac(16);
  set_hp(500);
  set_al(-1000);
  set_a_chat_chance(5);
  load_a_chat("Mr. Hand warps reality around him.\n");
  load_a_chat("Mr. Hand slashes with his knife, spilling "+RED+"blood"+NORM+" freely.\n");
  set_chance(30);
  set_spell_mess1(
"\nMr. Hand projects a spear of "+HIM+"warped reality"+NORM+" at his foe.\n");
  set_spell_mess2(
"\nMr. Hand projects a spear of "+HIM+"warped reality"+NORM+" at you.\n");
  set_spell_dam(30);
}
