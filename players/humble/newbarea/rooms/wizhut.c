/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIB+"Wizard's Hut"+NORM;
    long_desc =
    "The hut is quite expansive. There is a fireplace along the east\n"+
    "Wall of the hut with a cauldron inside it. There is a narrow hall\n"+
    "in the exact center of the room which opens up into a second room.\n"+
    "A small wooden table sits against the west wall along with a set\n"+
    "of chairs. There is something magical about this hut but you\n"+
    "can't quite put your finger on it\n";

    items =
    ({
    "cauldron",    "A cauldron sitting inside the fireplace",
    "fireplace",    "A fireplace that seems to be burning a small amount of brush",
    "room",   "A second room beyond a narrow hall",
    "table",    "A small wooden table with 4 legs that sits about 3 feet off the ground",
    "hut",    "The hut seems magical and enchanting",
     "hall",    "A short narrow hallway that leads into the next room",
    "chairs",    "A set of chairs that sits by the table",
    "wall",   "The wall is made of a thick tree, there are still shavings and knots on them",
    "brush",  "There is some soft brush sitting beside the fire, waiting to be burnt",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/wizhut2",        "north",
    "/players/humble/newbarea/rooms/garden4",        "out",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/elderelf.c"), this_object());
    add_smell("main",    "It smells strange here, almost like cinnamon powder.\n");
    add_feel("table",    "The table feels like a hard oak tree.\n");
    add_feel("chairs",    "The chairs feel like dogwood with a soft birch tree seating.\n");
    add_feel("fireplace",    "I wouldn't place your hand in there if I was you.\n");
    add_feel("cauldron",   "You WANT to burn yourself??\n");
    add_sound("main",    "The hut is quiet, not much to listen to.\n");
  }
}
