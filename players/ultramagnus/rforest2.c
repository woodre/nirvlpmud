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
TWO_EXIT("players/ultramagnus/rforest1.c", "west",
        "players/ultramagnus/rforest3.c", "north",
        "Red Forest",
       "You are in the Red Forest.  There is a thick growth of trees\n" +
       "blocking your way east.  There is a plain of red grass to the North.\n", 1)
up()
{
       call_other(this_player(), "move_player", "up#players/ultramagnus/redtree.c");
       return 1;
}
