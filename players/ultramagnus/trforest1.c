#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
       object tree;
       tree = clone_object("players/ultramagnus/rtree.c");
move_object(tree, this_object());
}
TWO_EXIT("players/ultramagnus/forest3.c", "west",
        "players/ultramagnus/rforest2.c", "east",
        "Red Forest",
        "You are in the Red Forest. You see the main path to the west.\n" +
        "There are several trees with vibrant Red leaves about.\n", 1)
init()
{
       add_action("climb","climb");
}
climb()
{
       call_other(this_player(), "move_player", "climb#players/ultramagnus/redtree.c");
       return 1;
}
