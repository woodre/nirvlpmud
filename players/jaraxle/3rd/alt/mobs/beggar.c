#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("beggar");
   set_alias("beggar");
   set_race("human");
   set_short("Beggar");
   set_long(
      "A really filthy looking, poor beggar.\n");
   
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
      "The beggar dies, pity.\n");
   move_object(gold,environment());
   return 0; }

