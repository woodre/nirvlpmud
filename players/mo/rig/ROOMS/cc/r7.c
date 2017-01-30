inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Command Center - Chinle Oil Platform");
   set_long(
      "This is the southern part of an open room that has several windows\n"+
      "to the west and north that overlook the platform. The floor has thin\n"+
      "carpetting.  A small set of stairs lead up to a raised section of the\n"+
      "room where computers are monitoring well-production.\n");
   
   
   add_exit("/players/mo/rig/ROOMS/cc/r8.c","north");
   add_exit("/players/mo/rig/ROOMS/cc/r5.c","east");
   
   add_item("windows","Large glass windows that give a view of the oil platform.\n");
   add_item("floor","A floor with cheap, thin blue carpetting.\n");
   add_item("stairs","Three steps that lead up to a raised area in the middle of the room.\n");
   add_item("computers","Top of the line computers that monitor the wells.\n");
   
}



