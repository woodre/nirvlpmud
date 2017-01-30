#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("wolf");
   set_alias("animal");
   set_alt_name("wolf");
   set_race("wolf");
   set_short("A wolf");
   set_long(
      "A large wolf, with deadly fangs.\n");
   set_level(6);
   set_hp(80+random(10));
   set_al(0);
   set_wc(11);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance(25);
   load_chat("The wolf growls angrilly.\n");
   load_chat("The wolf howls.\n");
   set_dead_ob(this_object());
   set_wander(25, 0, ({ "out" }));
   
}

monster_died() {
   object fur;
   
   fur = clone_object("players/jaraxle/cont/animals/skin.c");
   fur->set_short("Wolf fur");
   fur->set_value(300);
   move_object(fur),environment(TO);
   tell_room(environment(this_object()),
      "The wolf lets out an loud howl as it falls dead.\n");
   
   return 0; }
