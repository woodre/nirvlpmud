#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("snake");
   set_alias("trail snake");
   set_alt_name("snake");
   set_race("creature");
   set_short(HIG+"A trail snake"+NORM);
   set_long(
      "A long, thin, brown snake with light tan slanted stripes crossing over its body.\n");
   
   set_level(12);
   set_hp(180+random(21));
   set_al(0);
   set_wc(16);
   set_ac(9);
   set_aggressive(0);
   
   set_dead_ob(this_object());
   
}

monster_died() {
   tell_room(environment(this_object()),
      "The snake twitches violently before it lays limp.\n");
   MOCO("/players/jaraxle/3rd/volcano/items/skin.c"),environment());
return 0; }

