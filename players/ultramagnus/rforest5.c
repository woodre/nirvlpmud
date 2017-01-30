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
THREE_EXIT("players/ultramagnus/rforest3.c", "east",
        "players/ultramagnus/rforest1.c", "south",
       "players/ultramagnus/forest2.c", "west",
        "Red Forest",
       "You are in the Red Forest.  \n" +
       "There is a thick growth of tress blocking your way north.\n", 1)
up()
{
       call_other(this_player(), "move_player", "up#players/ultramagnus/redtree5.c");
       return 1;
}
