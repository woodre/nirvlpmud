#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
object hut;
if(!present("hut")){
       hut=clone_object("players/ultramagnus/ghut.c");
       move_object(hut, this_object());
}
}
TWO_EXIT("players/ultramagnus/bforest2.c", "east",
       "players/ultramagnus/golumhut.c", "west",
       "Small Trail",
       "There is a little space here between the trees.  You see\n" +
       "several old trees that are lying on the ground. They look\n" +
       "as if they have been lying there for ages.  There is a small\n" +
       "filthy looking dwelling to the west.\n",1)
