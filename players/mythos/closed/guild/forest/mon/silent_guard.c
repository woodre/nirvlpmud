#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("demon");
  set_short();
  set_race("guard");
  set_gender("demon");
  set_alias("nightmare");
  set_long("A thing of mist....\n");
  set_hp(500);
  set_level(23);
  set_al(-1000);
  set_wc(30);
  set_ac(21);
  set_heal(5,20);
  set_a_chat_chance(10);
  load_a_chat("The mist lashes out!\n");
  load_a_chat("The mist flashes with suddenly brilliance!\n"); 
  set_chance(40);
  set_spell_dam(60);
  set_spell_mess1("The mist flashes with sudden brilliance!\n");
  set_spell_mess2("You feel a great electrical shock run through you!\n"); 
}
