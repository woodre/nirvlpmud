#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruins of "+HIY+"Celestia"+NORM);
 set_long(
 "  Willow trees stand to the north and south of the cobblestone road.\n"+
 "Behind them stand homes in various states of ruin, walls crumbling,\n"+
 "and grown over with vines and weeds.  The road extends east and west\n"+
 "from here.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"r4.c","west");
add_exit(PLAIN+"re2.c","east");
}
}
