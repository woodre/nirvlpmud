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
    HBYEL+HIR+"The path begins to widen greatly now.  The moon shines dimly upon\n"+NORM+NORM+
    HBYEL+HIR+"the path behind you.  There is an eerie purplish, blueish glow coming\n"+NORM+NORM+
    HBYEL+HIR+"from further along the path where it begins to open into what seems\n"+NORM+NORM+
    HBYEL+HIR+"to be a field. The sound of children singing is heard faintly.\n"+NORM+ NORM;

    items =
    ({
    "path", "A wide path traveling through the woods, it's becomes dim as you travel it",
    "field",    "A purplish, blueish glowing field. It has a friendly, yet subconsciously eerie feeling",
    "woods",    "The trees look small from here they are so far away now",
    "moon",   "The moon shines brightly down upon you, it seems to loom right over the earth",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/faeriering",        "north",
    "/players/humble/newbarea/rooms/path2",        "south",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/largeelf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());
    add_smell("main",  "It smells fresh here, with an earthy aroma.\n");
    add_sound("main",    "You hear the soft voices of little children singing, it sounds like little girls.\n");
  }
}

