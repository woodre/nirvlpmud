inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/linus/def.h"
  id(str) { return str=="bee" || str=="honey bee"; }
  reset(arg)  {
    ::reset(arg);
    if(arg) return; 
  set_aggressive(0);
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_name("bee");
  set_short("A "+YEL+"honey"+NORM+" bee");
  set_long(
  "The bee flies around in search of flowers.  Small sacks of honey hang\n"+
  "from his legs, and a small stinger protrudes from his backside.\n");
  set_assist("/players/linus/Newbie/NPC/bee2.c", 5, 3, 9);
 /* Clones a bee2.c every 5 seconds, 3 allowed in the room at a time, and 9 total */
  set_dead_ob(this_object());
  }
  monster_died() {
   tell_room(environment(TO),"As the bee hits the ground, his stinger is knocked off.\n");
     move_object(clone_object("/players/linus/Newbie/obj/stinger.c"),
  environment(this_object()));
  return 1;
  }
