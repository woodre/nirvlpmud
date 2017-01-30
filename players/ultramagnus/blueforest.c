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
       tree = clone_object("players/ultramagnus/btree.c");
       move_object(tree, this_object());
}
}
TWO_EXIT("players/ultramagnus/forest4.c", "east",
        "players/ultramagnus/bforest1.c", "north",
        "Blue Forest",
        "You are in the Blue Forest. You see the main path to the east.\n" +
       "There seems to be a path going south leading to a bridge\n" +
       "of sorts.  To the west through the trees you see a very deep\n" +
       "valley or gorge.  It seems very dark in that direction.\n", 1)
up()
{
       call_other(this_player(), "move_player", "up#players/ultramagnus/bluetree.c");
       return 1;
}
