#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   set_name(HIW+"Rabbit"+NORM);
   set_alias("rabbit");
   set_alt_name("white rabbit");
   set_race("creature");
   set_short(HIW+"Rabbit"+NORM);
   set_long(
      "A cute, fuzzy "+HIW+"white"+NORM+" rabbit.\n");
   set_wander(40, 0, ({ "back" }));
   set_level(3);
   set_hp(40+random(15));
   set_al(0);
   set_wc(7);
   set_ac(3);
   set_aggressive(0);
   set_dead_ob(this_object());
   set_chat_chance(25);
   load_chat("The rabbit wiggles its nose.\n");
   set_a_chat_chance(15);
   load_a_chat("The rabbit gnaws on you!\n");
}

monster_died() {
   tell_room(environment(this_object()),
      "The rabbit falls lifeless to the ground.\n");
   MOCO("/players/jaraxle/3rd/warrior/weaps/foot2.c"),environment());
return 0; }
