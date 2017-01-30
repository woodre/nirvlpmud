#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;

set_name("bole");
set_race("human");
set_short("Bole Sneffer");
set_alias("bole");
set_long(
  "Bole is Jinx Sneffer's second son and younger brother to Naz Sneffer.\n"+
  "He is just beginning to learn the logging trade, and works with Bole.\n"+
  "He hooks the logs to the horse team with his choker chain.\n");

set_level(7);
set_hp(80 +random(30));
set_al(0);
set_wc(8 +random(4));
set_ac(4 +random(2));
set_whimpy(1);
weapon=clone_object("/players/fakir/woods/WEP/choker.c");
move_object(weapon,this_object());
}

