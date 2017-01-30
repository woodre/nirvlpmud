inherit "obj/monster.c";
#include "/players/fakir/color.h"

reset(arg)  {
  object treasure;
  ::reset(arg);
  if(arg) return;
add_money(250);
set_name("fairy");
set_race("fairy");
set_short(MAGENTA+"Guardian Fairy"+OFF);
set_long(
"     Without any armor and only a small dagger to fight\n"+
"with, this guard does not look to be a difficult opponent.\n"+
"The fairy guardian's wings have been clipped by the king to\n"+
"keep him from taking flight and running from battle.\n");


set_level(8);
set_hp(120);
set_al(-200);
set_wc(12);
set_ac(7);
set_aggressive(0);

treasure=clone_object("/players/fakir/woods/WEP/sdagger.c");
move_object(treasure,this_object());

}

