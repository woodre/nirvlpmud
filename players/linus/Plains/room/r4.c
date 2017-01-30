#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruins of "+HIY+"Celestia"+NORM);
 set_long(
 "  In the center of the intersection stands a large willow tree, having\n"+
 "pushed the stones of the road into piles around its base.  Weeds and\n"+
 "grass grow up through the many stones of the road.  The road branches\n"+
 "in four directions here.\n");
add_item("tree","A large willow tree that has pushed its way up through the roadway");
add_item("road","An old cobblestone road which branches off in various directions");
add_item("weeds","Various plants that have grown up through the neglected road");
add_item("weed","A small plant that has grown up through the neglected road");
add_item("grass","Green and brown grass grows wherever it can");
add_item("cobblestone","Various colored and sized stones that make up the roadway");
add_item("stone","A cobblestone which was used to make the road");
add_item("willow","A large willow tree that has pushed its way up through the roadway");
add_exit(PLAIN+"r3.c","south");
add_exit(PLAIN+"r5.c","north");
add_exit(PLAIN+"re1.c","east");
add_exit(PLAIN+"rw1.c","west");
}
}
