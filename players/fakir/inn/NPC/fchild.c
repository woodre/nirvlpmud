#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object treasure;
  ::reset(arg);
  if(arg) return;

set_name("tinkers child");
set_alias("child");
set_alt_name("missila");
set_race("human");
set_short("Tinkers Child");
set_long(
  "Impatiently waiting in the room of the inn for her father, Missila is\n"+
  "not at all pleased.  She is anxious to be on the road home so she can\n"+
  "play with her friends.\n"); 
set_level(5);
set_hp(75);
set_al(500);
set_wc(9);
set_ac(5);
set_aggressive(0);
set_dead_ob(this_object());
treasure=clone_object("/players/fakir/inn/OBJ/doll.c");
move_object(treasure,this_object());

}

