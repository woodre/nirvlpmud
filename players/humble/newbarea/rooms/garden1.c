/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIG+"Enchanted Garden"+NORM;
    long_desc =
    HBGRN+"You arrive at what seems to be a small garden. The night is well\n"+NORM+
    HBGRN+"lit and you can see everything perfectly fine.  There are roses and\n"+NORM+
    HBGRN+"bushes that cover certian spots around the garden.  There is a white\n"+NORM+
    HBGRN+"picket fence dividing the garden from the forest.  The grass about\n"+NORM+
    HBGRN+"you is moist from the dew which seems to cover every blade. A slight\n"+NORM+
    HBGRN+"breeze is felt. There is a humming noise coming from the woods\n"+NORM+
    HBGRN+"all around. There is a large portal whirling behind you that will\n"+NORM+
    HBGRN+"take you back to where you came from if you wish.\n"+NORM;
    HBGRN+"where you came from.\n"+NORM;
    items =
    ({
    "garden",    "A beautiful garden, it seems to glow with a vibrant light",
    "bushes",    "Small green bushes clutter the area, they seem beautiful",
    "fence",    "A white picket fence that seperates the garden from the forest",
    "picket fence",   "A white picket fence, it seperates the garden from the forest",
    "grass",    "The grass glows a glorious green and seem to be covered in dew",
    "forest",    "Beyond the garden is a dark forest, where the light it lost due to the trees",
    "roses",    "Wonderful red and white roses clutter the garden",
    "portal",    "A blue swirling portal that you could leave "+HIB+"back"+NORM+" into",
    "trees",    "The trees block the moonlight from illuminating the contents of the forest",
    "woods",    "The woods seem to surround the garden",
    });
    dest_dir =
    ({
    "/players/humble/area1/rooms/entrance",         "back",
    "/players/humble/newbarea/rooms/garden2",        "north",
    });
    add_smell("main", "It smells fresh here, as if it just rained.\n");
    add_smell("rose", "You catch some dew on your nose as you smell the roses.\n");
    add_feel("rose", "The roses have soft petals and a strong stem.\n");
    add_sound("main", "There is a calming humming sound that you cannot seem to escape.\n");
    add_feel("fence", "The fence is made of wood and evenly painted, it's perfect.\n");
    add_feel("picket fence", "The fence is made of wood and evenly painted, it's perfect.\n");
    add_feel("roses", "The roses have soft petals and a strong stem.\n");
    add_feel("bush", "The bush has strong, smooth almost glossy leafs.\n");
    add_feel("bushes", "The bush has strong, smooth almost glossy leafs.\n");
    add_feel("trees", "The trees are too far away to touch.\n");
    add_feel("tree", "The trees are too far away to touch.\n");
    add_feel("forest", "The trees are too far away to touch.\n");
    add_feel("woods", "The trees are too far away to touch.\n");
    add_feel("grass", "The grass is incredibly soft and damp.\n");
    add_smell("roses", "You catch some dew on your nose as you smell the roses.\n");
  }
}

