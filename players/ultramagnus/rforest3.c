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
TWO_EXIT("players/ultramagnus/rforest5.c", "west",
        "players/ultramagnus/rforest2.c", "south",
        "Red Forest",
       "You are in the Red Forest.  There is a grove to the east.\n" +
       "There is a thick growth of tress blocking your way north.\n", 1)
up()
{
       call_other(this_player(), "move_player", "up#players/ultramagnus/redtree.c");
       return 1;
}
