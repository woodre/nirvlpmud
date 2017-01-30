#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruined home");
 set_long(
 "  Tall grass and weeds dominate what was once a beautiful lawn.\n"+
 "The home that once stood here has been reduced to a pile of rubble,\n"+
 "the only surviving structure being a tall chimney.  The main road\n"+
 "passes to the west, and another to the north, beyond some willow\n"+
 "trees.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_object("/players/linus/Plains/NPC/Soul.c");
add_exit(PLAIN+"r3.c","west");
}
}
