#include "/players/linus/def.h"
inherit "/obj/treasure.c";
id(str) { return str=="spring" || str=="coil spring" || str=="large coil spring" || str=="large spring"; }
reset(arg) {
 if(arg) return;
 set_short("A large coil spring");
 set_long(
 "A large, heavy duty coil spring.  It has some remnants of orange fur\n"+
 "which hang from the coils.  One might be able to 'hop' to the 'green'\n"+
 "if so desired.\n");
 set_weight(1);
 set_value(550);
}
init() {
 ::init();
 add_action("hop_spring","hop");
}
hop_spring(string str) {
 if(!str || str!="green") { FAIL("Do what?\n"); return 0; }
 if(environment() != this_player()) return (FAIL("You must pick up the spring to bounce on it.\n"),0);
 write("You hop on the spring and bounce to a different place!\n");
 this_player()->move_player("bouncing to a different place#/room/vill_green");
 move_object(this_object(),"/room/void");
 destruct(this_object());
 write("The spring crumbles into pieces, no longer of any use.\n");
 return 1;
}
