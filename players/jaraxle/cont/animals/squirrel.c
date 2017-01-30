#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("squirrel");
   set_alias("animal");
   set_alt_name("squirrel");
   set_race("squirrel");
   set_short(YEL+"A squirrel"+NORM);
   set_long(
      "A small brown squirrel.\n");
   set_level(5);
   set_hp(70+random(10));
   set_al(0);
   set_wc(9);
   set_ac(4);
   set_aggressive(0);
   set_chat_chance(20);
   load_chat("The squirrel wiggles its nose.\n");
   load_chat("The squirrel quickly looks around the area.\n");
   load_chat("The squirrel cleans its face.\n");
   set_dead_ob(this_object());
   set_wander(30, 0, ({ "out" }));
   
}

monster_died() {
   object fur;
   
   fur = clone_object("players/jaraxle/cont/animals/skin.c");
   fur->set_short("Squirrel fur");
   fur->set_value(200);
   move_object(fur),environment(TO);
   tell_room(environment(this_object()),
      "The squirrel lets out a final squeek before death.\n");
   return 0; }
