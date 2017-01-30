#include "/players/linus/def.h"
inherit "/obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("hoe");
   set_short("A garden hoe");
   set_long(
    "A simple garden hoe.  It is used for tending gardens, but could\n"+
    "also be used as a weapon if needed.\n");
   set_type("spear");
   set_class(12);
   set_weight(1);
   set_value(350);
   set_hit_func(this_object());
}
weapon_hit(attacker) {
int blah;
blah = random(5);
if(blah>3) {
 say("The hoe slashes through flesh, leaving a "+HIR+"bloody"+NORM+" wound.\n");
 write("The hoe slashes through flesh, leaving a "+HIR+"bloody"+NORM+" wound.\n");
}
}
