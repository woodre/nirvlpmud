#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruins of "+HIY+"Celestia"+NORM);
 set_long(
 "  On either side of the cobblestone road are piles of rubble that were\n"+
 "once homes to citizens of Celestia.  A chimney stands to the east, the\n"+
 "only part of the house still standing.   To the west, nothing but a\n"+
 "weed covered pile is visible.  The cobblestone road travels south out\n"+
 "of the city, as well as to the north.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"r2.c","south");
add_exit(PLAIN+"r4.c","north");
add_object(PNPC + "Soul.c",2);
}
}
init() {
 ::init();
add_action("east","east");
add_action("west","west");
}
east() {
TP->move_player("east#"+PLAIN+"r3a.c");
return 1;
}
west() {
write("The weeds are too thick to pass through.\n");
return 1;
}
