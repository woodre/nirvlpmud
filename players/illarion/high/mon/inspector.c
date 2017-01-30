inherit "obj/monster";
#include "/players/illarion/dfns.h"
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("inspector");
  set_alias("man");
  set_race("human");
  set_short("A man in a grey trenchcoat");
  set_long(
"This man's every line says 'policeman'.  He walks like a cop, moves like a\n"+
"cop, and eyes you suspiciously like a cop.  He probably carries a pistol\n"+
"underneath his long grey raincoat, as well.");
  set_level(17);
  set_hp(425+random(75));
  set_al(100);
  set_wc(24);
  set_ac(14);
  add_money(900);
  set_gender("male");
  set_chat_chance(5);
  load_chat("The inspector says, \"Who IS this man?\"\n");
  load_chat("The man in the trenchcoat paces around.\n");
  set_chance(10);
  set_spell_dam(20);
  set_spell_mess1(
"The Inspector pulls out his police special and fires at your chest.");
  set_spell_mess2(
"The Inspector pulls a gun out of his trenchcoat, aims, and fires.");
}
