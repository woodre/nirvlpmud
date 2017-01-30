#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("The Mansion - first floor");
 set_long(
 "  Light peers into the house through the open door in the west wall\n"+
 "as well as through some holes where windows once were.  The room is\n"+
 "empty, having been picked clean by looters years ago.  A thick layer\n"+
 "of dust covers the stone floor, only breaking for some small foot\n"+
 "prints that disappear into a hole in the southern wall.  A stairway\n"+
 "leads to the upper floor from the northeast corner of the room, but\n"+
 "all the other exits are blocked by fallen rocks.\n");
 set_chance(8);
 add_msg("The light causes strange shadows throughout the room.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"re3a.c","out");
add_exit(PLAIN+"re3c.c","up");
add_exit_msg("up","You cautiously climb up the stairs.\n","caustiously climbs up the stairs\n");
add_object("/players/linus/Plains/NPC/mouse.c");
 }
}
