#include "/players/tristian/lib/ClubFeddefine.h"
inherit "obj/treasure.c";

reset(arg) {
  if(arg) return;
   
  set_id("jail key");
  set_alias("key");
  set_short(HIR+"Club Fed"+NORM+" Cell Key");
  set_long(
    "An old fashioned jail key. It's flat, and only fits the doors\n"+
    "in "+HIG+"Club"+HIR+"Fed"+NORM+".\n");
   set_value(0);
   set_weight(1);
}
