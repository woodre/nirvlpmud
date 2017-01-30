#include "/players/linus/def.h"
inherit "/obj/weapon.c";
 reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("sword");
 set_short("A "+RED+"rusted"+NORM+" sword");
 set_long(
 "A rusted sword that isn't in good shape, but is still\n"+
 "functional.\n");
 set_class(10);
 set_type("sword");
 set_value(1000);
 set_weight(2);
 set_hit_func(TO);
}
weapon_hit(attacker) {
int blah;
blah = random(5);
if(blah>3) {
 say("Some "+RED+"rust"+NORM+" falls from the blade as it strikes true.\n");
 write("Some "+RED+"rust"+NORM+" falls from your blade as it strikes true.\n");
}
}
