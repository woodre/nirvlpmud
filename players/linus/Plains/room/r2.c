#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruins of "+HIY+"Celestia"+NORM);
 set_long(
 "  A weathered and crumbling archway stands to the south, guarding the\n"+
 "entrance of the city.  Weeds dominate the cobblestone road that once\n"+
 "supported the heavy traffic of the city.  Buildings in various states\n"+
 "of ruin stand near the road, becoming shadows off in the distance.  A\n"+
 "small stone guard shack stands to the east, its rotted wooden door\n"+
 "hanging open.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"r1.c","south");
add_exit(PLAIN+"r3.c","north");
}
}
init() {
 ::init();
 add_action("head_east","east");
}
head_east() {
  write("You cautiously enter the shack.\n");
  TP->move_player("into the shack#"+PLAIN+"r2a.c");
 return 1;
}
