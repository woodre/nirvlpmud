#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT\
       add_action("up","climb");
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
       object tree;
if(!present("tree")){
       tree = clone_object("players/ultramagnus/rtree.c");
       move_object(tree, this_object());
}
}
THREE_EXIT("players/ultramagnus/forest3.c", "west",
        "players/ultramagnus/rforest2.c", "east",
       "players/ultramagnus/rforest5.c", "north",
        "Red Forest",
        "You are in the Red Forest. You see the main path to the west.\n" +
        "There are several trees with vibrant Red leaves about.\n", 1)
up()
{
       call_other(this_player(), "move_player", "up#players/ultramagnus/redtree.c");
       return 1;
}
