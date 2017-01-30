#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
 set_light(1);
 set_short("Cemetary of "+HIY+"Celestia"+NORM);
 set_long("\
  A rock wall and rusted gate stand to the west, once protecting the\n\
graves of fallen citizens of Celestia.  Grave markers stand in various\n\
states of decay throughout the cemetary.  Piles of dirt lay near large\n\
holes where the graves were dug up.  Tall grass and weeds dominate the\n\
ground, and a roadway travels east into the cemetary.\n");
 add_item("wall","Large rocks that have been stacked up to form a wall");
 add_item("rocks","Large rocks that were stacked up to form a wall");
 add_item("gate","A rusted gate that prevented or permitted entry into the cemetary");
 add_item("grave markers","Stones used to identify the location of graves in the cemetary");
 add_item("markers","Stones used to identify the location of graves in the cemetary");
 add_item("marker","A stone used to identify the location of a grave in the cmetary");
 add_item("stones","Stones used to identify the location of graves in the cemetary");
 add_item("stone","A stone used to identify the location of a grave in the cemetary");
 add_item("grass","Tall green and brown grass");
 add_item("tall grass","Tall green and brown grass");
 add_item("weeds","All sorts of green and brown weeds");
 add_item("roadway","\A path used to get around the cemetary.\n\
It is heavily overgrown with grass and weeds");
 add_item("road","\A path used to get around the cemetary.\n\
It is heavily overgrown with grass and weeds");
 add_item("graves","Large holes in the ground where citizens of Celestia were buried");
 add_item("grave","A large hole in the ground where a citizen of Celestia was buried");
 add_item("hole","A large hole in the ground where a citizen of Celestia was buried");
 add_item("holes","Large holes in the ground where citizens of Celestia were buried");
 add_item("piles","Piles of dirt removed from graves");
 add_item("pile","A pile of dirt removed from a grave");
 add_item("dirt","The dirt is dry and light brown in color");
 add_item("ground","\Where graves have been dug to bury citizens, it is overgrown with\n\
grass and weeds");
 add_exit(PLAIN+"re6.c","west");
 add_exit(PLAIN+"c2.c","east");
}
/* To make the area give necromancer guild spell bonus */
gravesite() { return "YES"; }
