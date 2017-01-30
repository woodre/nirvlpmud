#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("guardian");
   set_alias("guard");
   set_race("human");
   set_short("Guard");
   set_long(
      " A tall slender man in uniform.\n");
   set_chat_chance(15);
   load_chat("The guard warns you about what lies beyond the vortex.\n");
   load_chat("Guard says, 'The vortex is an "+HIR+"extremely"+NORM+" deadly realm.'\n");
   load_chat("Guard says, 'Enter the vortex at your own risk!'\n");
   set_level(12);
   set_hp(180+random(31));
   set_al(-1000+random(1001));
   set_wc(14);
   set_ac(11);
   set_aggressive(0);
   
   set_dead_ob(this_object());
   
   
   
}

monster_died() {
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(400+random(200));
   tell_room(environment(this_object()),
      "The guard dies with his final warning about beyond the vortex!\n");
   move_object(gold,environment());
   return 0; }

