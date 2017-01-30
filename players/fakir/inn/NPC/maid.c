#include "/players/fakir/color.h"
inherit "obj/monster.c";
  
reset(arg)  {
object armor;
  ::reset(arg);
  if(arg) return;
  
add_money(400);
set_name("maid");
set_alias("maid");
set_race("human");
set_short("Maid");
set_long(
  "Dressed in the knee length white apron of the inn, and of\n"+
  "an age to wear her hair in braids, this young woman makes\n"+
  "the beds and cleans the empty rooms each day.  Her wages\n"+
  "are meager so she depends upon the generosity of the guests\n"+
  "and hopes to recieve a nice tip now and then.\n"); 
set_level(11);
set_hp(165);
set_al(500);
set_wc(15);
set_ac(9);
set_aggressive(0);
set_dead_ob(this_object());
armor=clone_object("/players/fakir/inn/ARM/apron1.c");
move_object(armor,this_object());


}

