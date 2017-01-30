#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
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
  "players/eurale/RMS/warp.c","up",
  "players/eurale/Lab/l2.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Down","down");
}

Down() {
  TP->move_player("down#players/eurale/Lab/l2.c");
  write_file("/players/eurale/Lab/LOGS/labryinth",ctime(time())+
    "  "+capitalize(TPRN)+" was here.\n");
  return 1; }
