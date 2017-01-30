#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int count;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   if(!root()) {
     call_out("destroy_em", 0);
   }
   set_name("mosquito");
   set_alias("fire mosquito");
   set_alt_name("mosquito");
   set_race("creature");
   set_short(HIR+"Fire"+NORM+" mosquito");
   set_long(
      "A small, "+HIR+"red"+NORM+" mosquito fluttering in mid air.\n");
   
   set_level(5);
   set_hp(70+random(10));
   set_al(-1000+random(1001));
   set_wc(9);
   set_ac(4);
   set_aggressive(0);
   set_chat_chance(20);
   load_chat("The mosquito buzzes around your ear.\n");
   load_chat("The mosquito flutters in mid air.\n");
   load_chat("Tiny flames of fire ignite from the mosquito.\n");
   set_dead_ob(this_object());
   
   
}

monster_died() {
   object gold;
   gold = clone_object("obj/money");
   tell_room(environment(this_object()),
      "The mosquito drops to the ground and a few coins bounce from the corpse. (huh?)\n");
   gold->set_money(175+random(26));
   move_object(gold,environment());
   basename(this_object())->delete_count();
   return 0; }

query_count() { return count; }
add_count() { count ++; }
delete_count() { if(--count < 0) count = 0; }

void destroy_em()
{
    basename(this_object())->add_count();
    if(basename(this_object())->query_count() > 5) {
      move_object(this_object(), "/room/void");
      destruct(this_object());
    }
}
