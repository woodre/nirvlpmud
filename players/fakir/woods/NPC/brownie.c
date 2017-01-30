#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  object treasure;
  ::reset(arg);
  if(arg) return;

set_name("brownie");
set_race("fairy");
set_short(BROWN+"Brownie"+OFF);
set_long(
  "Dressed head to toe in brown, only the hands and face are uncovered.\n"+
  "The bowl of a small, long stemmed pipe is sticking up from a front\n"+ 
  "pocket.  Of all the fairy races, brownies are the most clever. If\n"+
  "attacked in battle, they are smart enough to run.\n");

set_level(2);
set_hp(30);
set_al(-100);
set_wc(6);
set_ac(3);
set_whimpy(1);
set_dead_ob(this_object());
treasure=clone_object("/players/fakir/woods/OBJ/lpipe.c");
move_object(treasure,this_object());
}

