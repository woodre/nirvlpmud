#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    Stairs lead up and down.  There is a door to the south leading\n"+
  "back to the west wing hallway.   A small window is on the north\n"+
  "wall, from the window one can barely see the parking lot.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the south, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/wstairway0.c","down",
  "/players/pestilence/hospital/room/whall.c","south",
  "/players/pestilence/hospital/room/wstairway2.c","up",
});
}
