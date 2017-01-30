/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = YEL+"Enchanted Pathway"+NORM;
    long_desc =
    HBYEL+HIR+"The path seems to thin out and disappear.  Further to the north is a\n"+NORM+NORM+
    HBYEL+HIR+"small garden that is quite cozy and looks very familiar. There\n"+NORM+NORM+
    HBYEL+HIR+"is smoke billowing from a hut far ahead of the path.  The\n"+NORM+NORM+
    HBYEL+HIR+"woods are silent...... such a strange place.\n"+NORM+NORM;

    items =
    ({
    "path",    "The path thins out and a soft patch of grass is found at the end",
    "grass",    "There is soft grass that seems to pick up where the path left off",
    "hut",    "You can see the outline of a hut, there is smoke billowing from it's chimney",
    "woods",    "The woods seem close and silent",
    "garden",    "A beautiful garden lies ahead",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/garden4",        "north",
    "/players/humble/newbarea/rooms/path5",        "south",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/largeelf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/largeelf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    add_feel("grass",    "The grass feels soft yet is matted down a bit.\n");
    add_sound("main",    "You hear absolutely nothing.\n");
    add_feel("main",    "You feel like there is something right behind you.\n");
     add_smell("main",    "You smell something burning, but it's not overwhelming, it seems to blend well with the smell of the woods.\n");
    add_feel("woods",    "You reach out to touch a tree but something seems to hold you back.\n");
  }
}
