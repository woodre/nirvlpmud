#include "/players/fred/ansi.h"
inherit "obj/monster.c";
object can;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("woodchuck");
set_race("animal");
set_short(BOLD+"Woodchuck"+NORM);
set_long(
  "  A crazy looking woodchuck that is grasping a can in\n"+ 
  "it's small paws.  You detect a slight odor of cheese!\n"); 
 
set_level(14);
set_hp(210);
set_al(-200);
set_ac(12);
set_aggressive(0);

  can = clone_object("/players/fred/forest/Obj/can1.c");
  move_object(can, this_object());
  command("wield can", this_object());
  set_wc(22); 
}
 

   

 


