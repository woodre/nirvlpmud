#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("deer");
   set_alias("animal");
   set_alt_name("deer");
   set_race("deer");
   set_short(YEL+"A deer"+NORM);
   set_long(
      "A white tailed deer.\n");
   set_level(5);
   set_hp(70+random(10));
   set_al(0);
   set_wc(9);
   set_ac(4);
   set_aggressive(0);
   set_chat_chance(20);
   load_chat("The deer wiggles its nose.\n");
   load_chat("The deer wiggles its tail.\n");
   set_dead_ob(this_object());
   set_wander(20, 0, ({ "out" }));
   
}

monster_died() {
   object fur;
   
   fur = clone_object("players/jaraxle/cont/animals/skin.c");
   fur->set_short("Deer skin");
   fur->set_value(200);
   move_object(fur),environment(TO);
   tell_room(environment(this_object()),
      "The deer falls to the ground, dead.\n");
   return 0; }
