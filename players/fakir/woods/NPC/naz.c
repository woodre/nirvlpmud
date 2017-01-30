#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;

set_name("naz");
set_race("human");
set_short("Naz Sneffer");
set_alias("naz");
set_long(
  "Naz is Jinx Sneffer's oldest son.  He has worked in the woods with his\n"+
  "father for many years.  As a result, he is muscular for a boy of only\n"+
  "sixteen years, and very handy with the peavey he holds.\n");

set_level(9);
set_hp(90 + random(40));
set_al(0);
set_wc(8 +random(6));
set_ac(4 +random(4));
set_whimpy(1);
weapon=clone_object("/players/fakir/woods/WEP/peavey.c");
move_object(weapon,this_object());
}

