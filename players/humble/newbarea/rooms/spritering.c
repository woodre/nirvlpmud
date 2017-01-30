/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = MAG+"Sprite Ring"+NORM;
    long_desc =
    HBCYN+"The path opens up into a small field. The field is spotted\n"+NORM+
    HBCYN+"with dozens of different colors that appear to be just splotches.\n"+NORM+
    HBCYN+"It's almost as if your hallucinating how surreal the colors are. The\n"+NORM+
    HBCYN+"grass here is moist and very long, it travels off into the woods\n"+NORM+
    HBCYN+"and part of it travels back onto the pathway.\n"+NORM;

    items =
    ({
    "path",   "You cannot clearly see the path from here",
    "field",    "You stand in the middle of a field but it's almost impossible to see",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/path4",        "south",
    "/players/humble/newbarea/rooms/path5",        "north",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/sprites.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/sprites.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/sprites.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/sprites.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/sprites.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/sprites.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());
    add_sound("main",   "You hear bickering as if it came from a strange distance but it's right near you.\n");
    add_feel("main",    "You feel a strange pinch everytime you focus on where you are.\n");
    add_smell("main",    "The smell here is strong of magic ointments and potions.\n");
  }
}
