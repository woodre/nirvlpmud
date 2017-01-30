#include "/players/softly/closed/ansi.h"
inherit "obj/monster";
object gold;

reset(arg){
::reset(arg);
 if(arg) return;

set_name("bumblebee");
set_race("insect");
set_alias("bee");
set_short(HIY+"B"+BOLD+BLK+"u"+HIY+"m"+BOLD+BLK+"b"+HIY+"l"+BOLD+BLK+"e"+HIY+"b"+BOLD+BLK+"e"+HIY+"e"+NORM+"");
set_long("A "+ HIY+"b"+BOLD+BLK+"u"+HIY+"m"+BOLD+BLK+"b"+HIY+"l"+BOLD+BLK+"e"+HIY+"b"+BOLD+BLK+"e"+HIY+"e"+NORM+" darts about the flowers.\n");
set_level(3);
set_hp(45);
set_al(-1000);
set_wc(7);
set_ac(4);
set_aggressive(0);
set_chat_chance (1);
load_chat("Bzzzzzzz....\n");
load_chat("The flowers sway in the mild breeze.\n");
set_dead_ob(this_object());
}
monster_died(ob) {
object stinger;
stinger = clone_object("/obj/weapon");
stinger->set_id("stinger");
stinger->set_short(BOLD+BLK+"Stinger"+NORM);
stinger->set_long("A bumblebee "+BOLD+BLK+"stinger"+NORM+".\n");
stinger->set_weight(1);
stinger->set_type("knife");
stinger->set_class(14);
stinger->set_alias("newbie_wep");
stinger->set_hit_func(this_object());
stinger->set_value(120);
  tell_room(environment(),"As the bumblebee dies his stinger falls to the earth.\n");
  move_object(stinger,environment(ob));
  return 1; 
}




