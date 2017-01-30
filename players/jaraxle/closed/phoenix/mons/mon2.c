#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name(RED+"Phoenix"+NORM);
   set_alias("phoenix");
   set_alt_name("bird");
   set_race("phoenix");
   set_short(RED+"Phoenix"+NORM);
   set_long(
      "A young and weak "+RED+"Phoenix"+NORM+".  Attacking these\n"+
      "legendary creatures is known to cause them to regenerate\n"+
      "into an aged, extremely dangerous foe.\n");
   set_level(15);
   set_hp(250+random(26));
   set_al(0);
   set_heal(5+random(16),3+random(3));
   set_ac(30);
   set_aggressive(0);
   set_wc(15);
   set_dead_ob(this_object());
}

monster_died() {
object blah;
blah = present("corpse", environment());
if(blah){ destruct(blah); }
   tell_room(environment(this_object()),
      "The "+RED+"Phoenix"+NORM+" is engulfed in flames!\n");
   MOCO("/players/jaraxle/closed/phoenix/mons/mon.c") ,TO);
   return 0; }

