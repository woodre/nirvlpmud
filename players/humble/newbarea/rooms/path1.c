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
    HBYEL+HIR+"A small path leading into the woods starts here. Since\n"+NORM+NORM+
    HBYEL+HIR+"you are no longer protected by the fence that outlined the garden\n"+NORM+NORM+
    HBYEL+HIR+"you are more prone to enemy encounter. The air still seems\n"+NORM+NORM+
    HBYEL+HIR+"crisp and a soft humming vibrates everything around. The path\n"+NORM+NORM+
    HBYEL+HIR+"is made from dirt and seems to nicely wind throughout the\n"+NORM+NORM+
    HBYEL+HIR+"woods without interferring with it's natural state.\n"+NORM+NORM;

    items =
    ({
    "garden",  "Looking back you spot the garden you just came from",
    "dirt",  "The dirt is nicely placed in almost the exact center of the path",
    "fence",   "You notice that there actually isn't a fence bordering you anymore",
    "path",    "A path that leads through the middle of the woods",
    "woods",    "The woods are dark and eerie",
    "forest",    "The forest is dark and eerie",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/path2",        "north",
    "/players/humble/newbarea/rooms/garden2",        "southeast",
    });

      move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());
      move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());

    add_sound("main", "You hear a soft buzz coming from the forest.\n");
    add_feel("main",    "You close your eyes and the path glows yellow in your mind.\n");
    add_feel("woods",    "You stretch your hand into the dark woods and get bit by freezing cold air.\n");
    add_feel("path",    "The path feels soft with tiny pebbles amongst it's earthy bed.\n");
    add_smell("main",    "The air seems crisp, there is a slight earthy aroma in the air.\n");
  }
}
