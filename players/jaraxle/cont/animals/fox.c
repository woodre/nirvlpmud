#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("fox");
   set_alias("animal");
   set_alt_name("fox");
   set_race("fox");
   set_short("A "+RED+"red tailed"+NORM+" fox");
   set_long(
      "A small fox with a dark red tail.\n");
   set_level(5);
   set_hp(70+random(10));
   set_al(0);
   set_wc(7);
   set_ac(7);
   set_aggressive(0);
   set_chat_chance(20);
   load_chat("The fox quickly surveys the area.\n");
   set_dead_ob(this_object());
   set_wander(30, 0, ({ "out" }));
   
}

monster_died() {
   object fur;
   
   fur = clone_object("players/jaraxle/cont/animals/skin.c");
   fur->set_short("Fox fur");
   fur->set_value(200);
   move_object(fur),environment(TO);
   tell_room(environment(this_object()),
      "The fox falls to the ground, dead.\n");
   return 0; }
