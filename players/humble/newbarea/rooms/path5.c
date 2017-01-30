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
    HBYEL+HIR+"The path seems to grow smaller as you step onto it,\n"+NORM+NORM+
    HBYEL+HIR+"a buzzing sound is still heard from behind you. Further\n"+NORM+NORM+
    HBYEL+HIR+"down the trail there appears to be figures moving about.\n"+NORM+NORM+
    HBYEL+HIR+"The trails leads further on into the woods.\n"+NORM+NORM;

    items =
    ({
    "path",    "A bright yellow, soft graveled dirt path",
    "figures", "You can see two lanky figures shoving one another in the distance",
    "dirt", "The dirt is a mix of sand, earth and gravel. It's bright yellow and very soft to the touch",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/path6",        "north",
    "/players/humble/newbarea/rooms/spritering",        "south",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/largeelf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/largeelf.c"), this_object());
    add_feel("main",    "You feel an eerie calm.\n");
    add_feel("path", "The path is rough as it has been walked many times.\n");
    add_sound("main",    "You hear a soft buzzing sound all around you.\n");
    add_smell("main",    "The surrounding area smells somewhat akward, it's crisp with a strange underlying odor.\n");
  }
}
