#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
     ::reset(arg);
  if(arg) return;

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

id(str){ return str == "jar_mummy"; }
monster_died() {
  tell_room(environment(this_object()),
     "The mosquito drops to the ground without a sound.\n");
return 0; }
