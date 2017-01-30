/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIG+"Enchanted Garden"+NORM;
    long_desc =
    HBGRN+"The garden seems to end here.  The picket fences end and two\n"+NORM+
    HBGRN+"paths unfold.  Both trail off into the woods in the north where the\n"+NORM+
    HBGRN+"humming becomes louder.  The air seems clean, not tainted with\n"+NORM+
    HBGRN+"the smell of blood and rotting flesh.\n"+NORM;

    items =
    ({
    "dirt", "A grainy, yellow-orange almost red form of dirt.  It is similar to sand",
    "woods",  "The woods are very eerie and dark, they seem to loom over the garden",
    "grass", "The grass is a healthy green with dew covering every blade",
    "garden",  "A magical garden with a vibrant glow",
    "path",   "A dirt path that seems very neatly placed at the end of the garden",
    "picket fences",  "White picket fences that outline the garden and break where the paths start",
    "fence",  "White picket fences that outline the garden and break where the paths start",
    "picket fence",  "White picket fences that outline the garden and break where the paths start",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/path1",        "northwest",
    "/players/humble/newbarea/rooms/path4",        "northeast",
    "/players/humble/newbarea/rooms/garden1",        "south",
    });
    add_smell("main", "The air is remarkably fresh, as if it had just rained.\n");
    add_feel("grass", "The grass is incredibly soft and damp.\n");
    add_sound("main", "There seems to be a soft humming noise that invades your senses.\n");
    add_feel("fence", "It's smooth and very glossy, almost surreal.\n");
    add_feel("picket fence", "It's smooth and very glossy, almost surreal.\n");
    add_feel("path",    "It's a soft, grainy feel, with a stronger consistency than sand.\n");
    add_smell("garden",   "There is something strange about the smell, crisp and clean.\n");
    add_listen("main", "You hear a soft wind blowing throughout the garden.\n");
  }
}

