#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;

set_name("Jinx");
set_race("human");
set_short("Jinx Sneffer");
set_alias("jinx");
set_long(
  "Jinx is a logger from the Two Rivers.  He supplies the town with the\n"+
  "wood to build its houses and shops.  He is dressed in tough buckskin\n"+
  "logging breeches tucked into heavy cork boots.\n");

set_level(10);
set_hp(150);
set_al(0);
set_wc(14);
set_ac(8);
set_whimpy(1);
weapon=clone_object("/players/fakir/woods/WEP/axe.c");
move_object(weapon,this_object());
}

