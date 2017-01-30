#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = "Hallway";
long_desc =
  "    This is a hallway within Steve and Blue's house.  At the end of the \n"+
  "hall is Steve's Bedroom.  To the south of here is the bathroom.  The\n"+
  "floor is entirely covered with red plush carpet.  The walls are covered \n"+
  "with a light blue paint.  There seems to be little of interest here.\n";
set_light(1);

items = ({
  "carpet","Red plush carpet spreading from the living room to Steve's bedroom",
  "paint","Light blue paint which covers the walls",
  "walls","Light blue paint covers the whole wall on each side",
});

dest_dir = ({
  "/players/pestilence/blue/rooms/sroom.c","east",
  "/players/pestilence/blue/rooms/room1.c","west",
  "/players/pestilence/blue/rooms/bath.c","south",
});

}
