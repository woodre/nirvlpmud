#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
 set_light(1);
 set_short("Cemetary of "+HIY+"Celestia"+NORM);
set_long(
"  Tall grass and weeds dominate this part of the cemetary.  Several\n"+
"grave markers still stand here, where others have crumbled into an\n"+
"unrecognizable state.  An overgrown road travels through the cemetary\n"+
"to the south and north.\n");
add_item("grass","Tall green and brown grass");
add_item("tall grass","Tall green and brown grass");
add_item("road","An overgrown road that traverses the cemetary");
add_item("marker","A stone used to identify the location of a grave in the cemetary");
add_item("stones","Stones used to identify the location of a grave in the cemetary");
add_item("markers","Stones used to identify the location of a grave in the cemetary");
add_item("grave marker","A stone used to identify the location of a grave in the cemetary");
add_item("stone","A stone used to identify the location of a grave in the cemetary");
add_exit(PLAIN+"c6.c","south");
}
