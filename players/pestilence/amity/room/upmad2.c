#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;


short_desc = ""+BLU+"Small Bedroom"+NORM+"";
long_desc =
  "    This is a small bedroom that belongs to a child.  There is a\n"+
  "small dresser on east wall.  Next to the dresser there is a toy box\n"+
  "filled with toys.  A bed sits in the middle of the room.  The bed has\n"+
  "been slept in and not remade afterwards.\n";
set_light(1);

items = ({
"bed","A very small bed, with a Bob the Builder comforter and pillow cases on the pillows",
"box","A square toy box with assorted toys in it",
"animals","Various stuffed animals",
"stuffed animals","Various stuffed animals",
"toy cars","Lots of toy cars, in various colors",
"cars","Lots of toy cars, in various colors",
"pillows","Two soft pillows with bob the builder on them",
"dresser","A small dresser sitting against the east wall",
"carpet","A blue carpet extends from wall to wall",
"toy box","A square toy box with assorted toys in it",
"toys","Lots of toy cars and stuffed animals",
});

dest_dir = ({
  "/players/pestilence/amity/room/upmad1.c","west",
});
}
