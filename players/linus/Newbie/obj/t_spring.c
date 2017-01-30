#include "/players/linus/def.h"
inherit "/obj/treasure.c";
id(str) { return str=="spring" || str=="coil spring" || str=="large coil spring" || str=="large spring"; }
reset(arg) {
 if(arg) return;
 set_short("A large coil spring");
 set_long(
 "A large, heavy duty coil spring.  It has some remnants of orange fur\n"+
 "which hang from the coils.  It might be fun to 'hop' around on it.\n");
 set_weight(1);
 set_value(350);
}
init() {
 ::init();
 add_action("hop_spring","hop");
}
hop_spring(string str) {
 if(!str || str!="spring") { FAIL("Do what?\n"); return 0; }
 if(environment() != this_player()) return (FAIL("You must pick up the spring to bounce on it.\n"),0);
 if(str=="spring") {
 write("You hop on the spring and bounce around!\n");
 say(TPN+" hops on the spring and bounces around!\n");
 return 1;
}
}
