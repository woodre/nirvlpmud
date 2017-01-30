#include "/players/feldegast/closed/ansi.h"
inherit "obj/monster.c";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("lizard");
set_short(HIG+"Lizard"+NORM);
set_long("This is a big lizard.\n");
set_al(0);
set_level(12);
set_wc(12);
set_ac(5);
set_hp(135);
set_aggressive(1);
set_dead_ob(this_object());
}
 
monster_died(ob) {
  tell_room(environment(), "As the lizard dies, you notice a mace left behind on the floor by some careless adventurer.\n");
  move_object(clone_object("/players/feldegast/wep/mace.c"),environment());
}
