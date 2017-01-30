#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
set_light(1);
set_short("Cemetary of "+HIY+"Celestia"+NORM); 
set_long(
"  Grave markers are scattered throughout the cemetary.  The graves are\n"+
"nothing more than large holes in the ground, having been dug up over\n"+
"time.  An overgrown road travels through the cemetary in an east and\n"+
"northwest direction.\n");
 add_item("grave markers","@markers");
 add_item("markers","Stones used to identify the location of graves in the cemetary");
 add_item("marker","A stone used to identify the location of a grave in the cmetary");
 add_item("stones","@markers");
 add_item("stone","@marker");
add_item("road","Little more than an overgrown path that aids travel through the cemetary");
 add_item("graves","Large holes in the ground where citizens of Celestia were buried");
 add_item("grave","A large hole in the ground where a citizen of Celestia was buried");
 add_item("hole","@grave");
 add_item("holes","@graves");
 add_item("dirt","The dirt is dry and light brown in color");
add_item("ground","Where graves have been dug to bury the dead");
 add_exit(PLAIN+"c2.c","north");
 add_exit(PLAIN+"c4.c","east");
}
/* To make the area give necromancer guild spell bonus */
gravesite() { return "YES"; }
