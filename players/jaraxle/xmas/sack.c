#include "/players/jaraxle/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("bow");
set_alias("bow");
set_short("A huge sack");
set_long(
  "A short curved bow made from flexible wood. \n");

set_type("bow");  /*  sword/knife/club/axe/bow/polearm  */
set_class(1);
set_weight(1);
set_value(0);
set_hit_func(this_object());
}


