inherit "obj/monster";
#include "/players/persephone/rooms.h"
object pelt;
reset(arg){
 ::reset(arg);
  if(arg) return;
  pelt=clone_object("players/persephone/treas/pelt.c");
  move_object(pelt, TOB);
  set_name("warg");
  set_alias("wolf");
  set_short("Evil Warg");
  set_long("An extremely evil and vile looking creature by some these creatures\n" +
           "are mistaken as wolves but they are much more savage and attack\n" +
           "on sight. Actually they are related to wolves but are evil and larger\n");
  set_level (13);
  set_wc(17);
  set_ac(10);
  set_hp(190);
  set_al(-150);
  set_aggressive(1);
  set_gender(0);
  set_chance(5);
  set_spell_dam(10);
  set_spell_mess1("The Warg snarls savagely");
  set_spell_mess2("You have just been bitten by the warg. Ouch!!!");
}
