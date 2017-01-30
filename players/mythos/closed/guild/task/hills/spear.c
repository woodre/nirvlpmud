#include "/players/mythos/closed/guild/def.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("spear");
  set_alias("drafnor");
  set_short(HIR+"Ruby Spear"+NORM);
  set_long("\n");
  set_class(18);
  set_weight(4);
  set_value(100000);
  set_hit_func(this_object());
}

query_gsave() { return 1;}
query_save_flag() { return 1;}

weapon_hit(attacker){

}

