#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Ruins of "+HIY+"Celestia"+NORM);
 set_long(
 "  The cobblestone road is overgrown with weeds and grass, leaving the\n"+
 "once level road uneven and pitted.  A vine covered fence surrounds a\n"+
 "crumbling house to the south, and willow trees have grown too thick to\n"+
 "the north to permit any travel in that direction.  The road leads to\n"+
 "the west and turns further east.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"re4.c","south");
add_exit(PLAIN+"re6.c","north");
add_exit(PLAIN+"c1.c","east");
 }
}
