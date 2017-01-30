#define tp this_player()->query_name()
#include "/players/cosmo/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("blade");
  set_alias("death");
  set_short(MAG+"Deathblade"+NORM);
  set_long(
    "\nCosmo's blade of terror.\n");
  set_type("sword");
  set_class(100);
  set_weight(1);
  set_value(0);
  set_hit_func(this_object());
}
