#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("bruce");
   set_alias("smith");
   set_race("human");
   set_short("Bruce, the Smith");
   set_long(
      "  A large, burly man with a long beard.  His skin\n"+
      "is covered with soot from the hearth and coal.\n");
   set_level(15);
   set_hp(290+random(31));
   set_al(0);
   set_wc(14);
   set_ac(20);
   set_aggressive(0);
   set_chat_chance(15);
   load_chat("Bruce hammers onto a piece of armor.\n");
   load_chat("Bruce fans the flames of the hearth.\n");
   load_chat("Bruce hammers onto a piece of armor.\n");
   set_dead_ob(this_object());
   
   
   
}

monster_died() {
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(100+random(200));
   tell_room(environment(this_object()),
      "The smith crashes to the ground, lifeless.\n");
   move_object(gold,environment());
   return 0; }

