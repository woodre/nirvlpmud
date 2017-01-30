#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("tiger");
   set_alias("animal");
   set_alt_name("tiger");
   set_race("tiger");
set_short("A "+YEL+"t"+BLK+"i"+YEL+"g"+BLK+"e"+YEL+"r"+NORM);
set_long("A large tiger.  It has deadly fangs\nand large, sharp claws.\n");
   set_level(17);
   set_hp(370+random(10));
   set_al(0);
   set_wc(26);
   set_ac(12);
   set_aggressive(0);
   set_chat_chance(20);
load_chat("The tiger snarls at you.\n");
load_chat("The tiger growls in a low, angry tone.\n");
   set_dead_ob(this_object());
   set_wander(10, 0, ({ "out" }));
   
}

monster_died() {
   object fur;
   
   fur = clone_object("players/jaraxle/cont/animals/skin.c");
   fur->set_short("Tiger fur");
   fur->set_value(2000+random(101));
   move_object(fur),environment(TO);
   tell_room(environment(this_object()),
      "The tiger falls to the ground with a loud crash.\n");
   return 0; }
