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
    HBYEL+HIR+"This path is well lit and seems to wind throughout the woods.\n"+NORM+NORM+
    HBYEL+HIR+"Behind you is the garden which you came from and in\n"+NORM+NORM+
    HBYEL+HIR+"front of you, the path seems to grow more broad. All sorts\n"+NORM+NORM+
    HBYEL+HIR+"of strange sounds are heard from further along the path.\n"+NORM+NORM;

    items =
    ({
    "trees", "The trees appears very still, they move only for the wind",
    "dirt", "The dirt is very earthy, grainy and is a dark red color",
    "path",    "A soft yellow dirt path which looks like it was just put here yesterday",
    "woods",    "The woods look cold and dark",
    "garden",    "You glance at the garden behind you, it seems so peaceful from here",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/spritering",        "north",
    "/players/humble/newbarea/rooms/garden2",        "southwest",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/elf.c"), this_object());

    add_feel("path",    "The path is soft and made with fresh dirt as if it was just placed there.\n");
    add_feel("main",    "You feel a strange calm as you wander the path.\n");
    add_sound("main",    "The wind blows through the trees softly.\n");
    add_smell("main",    "The air is smooth and refreshing.\n");
  }
}
