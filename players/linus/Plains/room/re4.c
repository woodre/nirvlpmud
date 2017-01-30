#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruins of "+HIY+"Celestia"+NORM);
 set_long(
 "  The cobblestone road is overgrown with weeds and grass, leaving the\n"+
 "road in disarray.  The road stops at a tall stone wall and turns to\n"+
 "the north here.  The wall is covered in vines and other growth, with\n"+
 "tall trees looming behind it.  The remains of a house, no more than\n"+
 "a pile of rubble, is to the south.  The road travels along the wall\n"+
 "to the north, and west through the remains of a neighborhood.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"re3.c","west");
add_exit(PLAIN+"re5.c","north");
 }
}
