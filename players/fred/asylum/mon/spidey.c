inherit "/obj/monster.c";
#include <ansi.h>
#include "/players/fred/defines.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  set_name("spider");
  set_race("critter");
  set_short("A spider");
  set_long(
    "  A small "+BLK+"black"+NORM+" spider.\n");
  set_level(8);
  set_al(-(random(100)));
  set_ac(7);
  set_wc(12);
  set_hp(110+(random(50)));
  set_gender("male");
  set_dead_ob(this_object());
  set_aggressive(0);
  }
  
  monster_died(){
   move_object(clone_object("/players/fred/asylum/obj/silk.c"),
   environment(this_object()));
   return 1;  
  }
