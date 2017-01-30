#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Guard shack");
 set_long(
 "  There is little left in this room, looters having taken anything of\n"+
 "value years ago.  The stone walls are still intact, with a window near\n"+
 "the door which the guards used to monitor traffic.  There are holes in\n"+
 "the wooden roof, and trickles of dust fall through them onto the dirt\n"+
 "floor.  The only furniture that has survived the looters and time is a\n"+
 "small stone bench along the northern wall.\n");
add_item("wall","A wall made of stone.  It still appears to be sturdy, withstanding the toll of weather and time");
add_item("bench","A small bench made of stone.  It is weathered and worn");
add_exit(PLAIN+"r2.c","out");
add_object("/players/linus/Plains/NPC/g_skel.c");
}
}
