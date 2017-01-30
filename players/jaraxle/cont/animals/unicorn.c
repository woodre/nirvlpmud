#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("unicorn");
   set_alias("animal");
   set_alt_name("unicorn");
   set_race("unicorn");
   set_short(HIW+"A Unicorn"+NORM);
   set_long("A mystical creature.  The unicorn\nis a horse, with a lovely horn on its head.\n");
   
   set_level(15);
   set_hp(400+random(10));
   set_al(1500);
   set_wc(20);
   set_ac(20);
   set_aggressive(0);
   set_chat_chance(20);
   load_chat("The unicorn eats some grass.\n");
   set_dead_ob(this_object());
   set_wander(40, 0, ({ "out" }));
   
}

monster_died() {
    MOCO("/players/jaraxle/cont/animals/horn.c"),environmenr(TO));
   tell_room(environment(this_object()),
      "The deer falls to the ground, dead.\n");
   return 0; }
