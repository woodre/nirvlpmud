#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
 set_light(1);
 set_short("Cemetary of "+HIY+"Celestia"+NORM); 
set_long(
"  Grave markers stand in various states of decay around the cemetary.\n"+
"Some of the graves have been dug up, leaving deep holes in the ground.\n"+
"Large piles of dirt are near the dug up graves, and an overgrown road\n"+
"travels north and west here.\n");
 add_item("grave markers","Stones used to identify the location of graves in the cemetary");
 add_item("markers","Stones used to identify the location of graves in the cemetary");
 add_item("marker","A stone used to identify the location of a grave in the cmetary");
 add_item("stones","Stones used to identify the location of graves in the cemetary");
 add_item("stone","A stone used to identify the location of a grave in the cemetary");
 add_item("grass","Tall green and brown grass");
 add_item("tall grass","Tall green and brown grass");
 add_item("weeds","All sorts of green and brown weeds");
 add_item("vines","Green vines that grow on a rock wall");
 add_item("vine","A green vine that grows on a rock wall");
 add_item("roadway","\A path used to get around the cemetary.\n\
It is heavily overgrown with grass and weeds");
 add_item("road","\A path used to get around the cemetary.\n\
It is badly overgrown with grass and weeds");
 add_item("graves","Large holes in the ground where citizens of Celestia were buried");
 add_item("grave","A large hole in the ground where a citizen of Celestia was buried");
 add_item("hole","A large hole in the ground where a citizen of Celestia was buried");
 add_item("holes","Large holes in the ground where citizens of Celestia were buried");
 add_item("piles","Piles of dirt removed from graves");
 add_item("pile","A pile of dirt removed from a grave");
 add_item("dirt","The dirt is dry and light brown in color");
 add_item("ground","\Where graves have been dug to bury citizens, it is overgrown with\n\
weeds and grass");
 add_item("wall","An old wall made of rocks.  It guards the southern side of the cemetary");
 add_item("rock wall","An old wall made of rocks.  It guards the southern side of the cemetary");
 add_item("rocks","Large rocks used in the construction of a wall");
 add_item("rock","A rock used in the construction of a wall");
 add_exit(PLAIN+"c4.c","west");
 add_exit(PLAIN+"c7.c","north");
}
/* To make the area give necromancer guild spell bonus */
gravesite() { return "YES"; }
