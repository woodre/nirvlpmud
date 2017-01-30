#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("bear");
   set_alias("animal");
   set_alt_name("bear");
   set_race("bear");
   set_short(BLK+"A black bear"+NORM);
   set_long("A huge "+BLK+"black bear"+NORM+".\n");
   set_level(17);
   set_hp(370+random(10));
   set_al(0);
   set_wc(24);
   set_ac(14);
   set_aggressive(0);
   set_chat_chance(20);
   load_chat("The black bear roars.\n");
   set_dead_ob(this_object());
   set_wander(10, 0, ({ "out" }));
   
}

monster_died() {
   object fur;
   
   fur = clone_object("players/jaraxle/cont/animals/skin.c");
   fur->set_short("Bear skin");
   fur->set_value(2000+random(101));
   move_object(fur),environment(TO);
   tell_room(environment(this_object()),
      "The bear falls to the ground with a loud crash.\n");
   return 0; }
