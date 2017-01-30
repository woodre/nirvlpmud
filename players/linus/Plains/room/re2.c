#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruins of "+HIY+"Celestia"+NORM);
 set_long(
 "  The cobblestone road is barely visible, being overgrown with weeds\n"+
 "and grass.  Stone houses stand to the north and south, their crumbling\n"+
 "walls overgrown with vines and weeds.  Weeds and willows dominate what\n"+
 "were once lavish lawns.  The road permits travel east and west.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"re1.c","west");
add_exit(PLAIN+"re3.c","east");
add_object("/players/linus/Plains/NPC/Soul.c");
 }
}
