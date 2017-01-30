#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("The Mansion - second floor");
 set_long(
 "  Sections of the roof have rotted through,  permitting the elements\n"+
 "to wreak havoc on the hardwood floor.  The room is empty, with the\n"+
 "exception of dust, leaves, and other miscellaneous items that have\n"+
 "entered through the holes in the roof.  A large window frame stands\n"+
 "in the eastern wall, the glass taken by looters years ago.  A stairway\n"+
 "in the northeastern corner of the room offers the only exit out.\n");  
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"re3b.c","down");
add_exit_msg("down","You cautiously walk down the stairs.\n","caustiously walks down the stairs.\n");
add_object("/players/linus/Plains/NPC/c_soul.c");
}
}
