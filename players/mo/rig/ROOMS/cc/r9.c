inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Command Center - Chinle Oil Platform");
   set_long(
      "This is the northern portion of an open room that has several\n"+
      "windows to the west and north that overlook the oil wells. The\n"+ 
      "floor has thin carpetting.  A small set of stairs lead up to a\n"+
      "raised section of the room where computers are monitoring\n"+
      "well-production. \n");
   
   add_exit("/players/mo/rig/ROOMS/cc/r8.c","south");
   add_exit("/players/mo/rig/ROOMS/cc/r3.c","east");
   
   add_item("wells","Wells #1-5 that are located on the Chinle Oil Platform\n");
   add_item("windows","Large windows that allow you to look at the oil platform.\n");
   add_item("computers","Computers monitoring well-production.\n");
   add_item("floor","The floor that you are standing on.  The carpet is blue.\n");
   add_item("stairs","Three steps that lead to a raised area.\n");
   
}
