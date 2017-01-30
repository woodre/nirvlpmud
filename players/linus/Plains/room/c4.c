#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
set_light(1);
set_short("Cemetary of "+HIY+"Celestia"+NORM); 
set_long(
"  Grave markers stand in various states of decay around the cemetary.\n"+
"The graves have been dug up, leaving large holes in the ground.  Large\n"+
"piles of dirt surround the graves.  An overgrown road travels through\n"+
"the cemetary in an east and west direction.\n");
 add_item("grave markers","Stones used to identify the location of graves in the cemetary");
 add_item("markers","Stones used to identify the location of graves in the cemetary");
 add_item("marker","A stone used to identify the location of a grave in the cmetary");
 add_item("stones","Stones used to identify the location of graves in the cemetary");
 add_item("stone","A stone used to identify the location of a grave in the cemetary");
add_item("road","A simple path that leads around the cemetary");
 add_item("graves","Large holes in the ground where citizens of Celestia were buried");
 add_item("grave","A large hole in the ground where a citizen of Celestia was buried");
 add_item("hole","A large hole in the ground where a citizen of Celestia was buried");
 add_item("holes","Large holes in the ground where citizens of Celestia were buried");
 add_item("piles","Piles of dirt removed from graves");
 add_item("pile","A pile of dirt removed from a grave");
 add_item("dirt","The dirt is dry and light brown in color");
add_item("ground","Where the graves are dug in the cemetary");
 add_exit(PLAIN+"c3.c","west");
 add_exit(PLAIN+"c6.c","east");
 add_exit(PLAIN+"c5.c","north");
 add_object(PNPC+"minion.c",random(2));
}
/* To make the area give necromancer guild spell bonus */
gravesite() { return "YES"; }
