/* **********************************************************************
*
********************************************************************** */

inherit "/obj/monster";
#include "/players/jareel/define.h"

  reset(arg) {
    ::reset(arg);
  if (arg) return;
  
  set_race("troll");
  set_al(-10);
  set_ac(14);
  set_wc(24);
  set_hp(350);
  set_level(17);
  add_money(1800+random(300));
  set_name("warrior");
  set_short("Troll warrior");
  set_long(
    "The troll stands in front of you with a daunting stance.\n"+
    "The warriors skin absorbs the abiant light.  Scars line\n"+
    "the body of this warrior like a mosaic of marks.\n");
  set_spell_mess1(HIK+"Darkness surrounds the troll.\n"+NORM);
  set_spell_mess2(HIK+"Darkness rushes from the troll into you\n"+NORM);
  set_chance(5);
  set_spell_dam(30);
}
