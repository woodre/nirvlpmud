#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
set_light(1);
set_short("Cemetary of "+HIY+"Celestia"+NORM); 
set_long(
"  Grave markers lie strewn about throughout the cemetary.  The graves\n"+
"have been dug up, leaving large holes in the ground. Dirt piles stand\n"+
"nearby.  An overgrown roadway travels out of the cemetary to the west,\n"+
"and leads through the cemetary to the north and south.\n");

add_item("grave markers","@markers");
add_item("markers","Stones used to identify the location of graves in the cemetary");
add_item("marker","A stone used to identify the location of a grave in the cmetary");
add_item("stones","@markers");
add_item("stone","@marker");
add_item("road","A path used to get around the cemetary");
add_item("roadway","@road");
add_item("graves","Large holes in the ground where citizens of Celestia were buried");
add_item("grave","A large hole in the ground where a citizen of Celestia was buried");
add_item("hole","@grave");
add_item("holes","@graves");
add_item("piles","Piles of dirt removed from graves");
add_item("pile","A pile of dirt removed from a grave");
add_item("dirt","The dirt is dry and light brown in color");
 add_exit(PLAIN+"c1.c","west");
 add_exit(PLAIN+"cr1.c","north");
 add_exit(PLAIN+"c3.c","south");
 add_object(PNPC+"minion.c",random(3));
}
/* To make the area give necromancer guild spell bonus */
gravesite() { return "YES"; }
