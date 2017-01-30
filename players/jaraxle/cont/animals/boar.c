#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("boar");
   set_alias("animal");
   set_alt_name("boar");
   set_race("boar");
   set_short(MAG+"A boar"+NORM);
   set_long(
      "A large pig with husks sticking out from its mouth.\n");
   set_level(5);
   set_hp(70+random(10));
   set_al(0);
   set_wc(9);
   set_ac(5);
   set_aggressive(0);
   set_chat_chance(20);
   load_chat("The boar squeals angrilly.\n");
   load_chat("The boar squeals.\n");
   load_chat("The boar squeals loudly.\n");
   set_dead_ob(this_object());
   set_wander(20, 0, ({ "out" }));
   
}

monster_died() {
   object fur;
   
   fur = clone_object("players/jaraxle/cont/animals/skin.c");
   fur->set_short("Boar skin");
   fur->set_value(200);
   move_object(fur),environment(TO);
   tell_room(environment(this_object()),
      "The boar lets out an awful squeal as it falls dead.\n");
   
   return 0; }
