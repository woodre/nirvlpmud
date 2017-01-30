#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   set_name("Rabbit");
   set_alias("rabbit");
   set_alt_name("black rabbit");
   set_race("creature");
   set_short(BLK+BOLD+"Rabbit"+NORM);
   set_long(
       "A cute, quick, fuzzy, "+BLK+BOLD+"black rabbit"+NORM+".\n");
   set_level(3+random(3));
   set_hp(75+random(50));
   set_al(0);
   set_wc(9+random(4));
   set_ac(6);
   set_aggressive(0);
   set_dead_ob(this_object());
   set_chat_chance(25);
   set_wander(30, 0, ({ "back" }));
   load_chat("The rabbit wiggles its nose.\n");
   set_a_chat_chance(15);
   load_a_chat("The rabbit gnaws on you!\n");
}

bye_bye(){
   say("The rabbit quickly hops into a bush.\n");
   destruct(this_object());
   return 1; }

monster_died() {
   tell_room(environment(this_object()),
      "The rabbit falls lifeless to the ground.\n");
   MOCO("/players/jaraxle/3rd/warrior/weaps/foot.c"),environment());
return 0; }

