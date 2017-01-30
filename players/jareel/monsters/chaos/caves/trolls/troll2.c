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
  set_name("troll");
  set_short("Troll mage");
  set_long(
    "This large hunched over form of a humanoid looms over\n"+
    "you.  The trolls eyes are narrowed slits focused along\n"+
    "its long narrow snout.\n");
  set_spell_mess1(HIK+"The troll releases a mass of dark energy.\n"+NORM);
  set_spell_mess2(HIK+"The troll waves his hand.\n"+
    "                dark energy washes over you"+NORM);
  set_chance(5);
  set_spell_dam(30);
}
