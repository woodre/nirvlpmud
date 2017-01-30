#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("bulette")) {
  move_object(clone_object("/players/eurale/Lab/NPC/bulette.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  A narrow, spiraling stairway goes both up and down from here.  The\n"+
  "pie-shaped steps have been cut from the solid stone that surrounds\n"+
  "you.  A faint light from above silhouettes the rough walls and pure\n"+
  "darkness lies below.\n";

items = ({
  "stairway","Curved steps that spiral around a central wall making\n"+
             "them disappear both up and down from here",
  "steps","Smooth, flat pads that are wider the farther they get from\n"+
          "the central wall",
  "wall","Chipped out of solid stone, they are rough and uneven",
});

dest_dir = ({
  "players/eurale/Lab/l1.c","up",
  "players/eurale/Lab/l3.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Down","down");
}

Down() {
if(present("bulette")) {
  write("The bulette SNAPS at your foot as you attempt to go down.\n");
  return 1; }
}
