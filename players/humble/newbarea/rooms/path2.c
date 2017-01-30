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
    HBYEL+HIR+"The path continues to wind and you can no longer tell where it\n"+NORM+NORM+
    HBYEL+HIR+"started nor where it ends. The air seems to get cleaner as\n"+NORM+NORM+
    HBYEL+HIR+"if it has just rained. The distance between the path and the\n"+NORM+NORM+
    HBYEL+HIR+"woods seems to grow greater the farther you travel\n"+NORM+NORM+
    HBYEL+HIR+"up the path.\n"+NORM+NORM;

    items =
    ({
    "path",    "A well lit, bright path leading through the woods",
    "woods",  "The woods instill a childhood fear within you, they are dark and terrible",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/path3",        "north",
    "/players/humble/newbarea/rooms/path1",        "south",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/faeries.c"), this_object());
    add_smell("main",    "The path smells clean, there is a very earthy aroma from the path.\n");
    add_feel("path",    "The path feels soft and well turned, as if it had just been walked upon.\n");
    add_feel("main",    "The world seems to be at peace here.\n");
    add_sound("main",    "You can hear singing in the great distance, odd.\n");
  }
}
