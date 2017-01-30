#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object weapon;
  ::reset(arg);
  if(arg) return;

set_name("tinkers child");
set_alias("child");
set_alt_name("brakas");
set_race("human");
set_short("Tinkers Child");
set_long(
  "Impatiently waiting in the room of the inn for his father, Brakas is\n"+
  "very unhappy.  He is anxious to get outside so he can try out the new\n"+
  "slingshot his father bought for him at the trading post.\n"); 
set_level(5);
set_hp(75);
set_al(500);
set_wc(9);
set_ac(5);
set_aggressive(0);
set_dead_ob(this_object());
weapon=clone_object("/players/fakir/inn/WEPS/sling.c");
move_object(weapon,this_object());

}

