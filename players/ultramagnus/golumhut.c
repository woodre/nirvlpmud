#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
object ring;
if(!present("ring")){
       ring=clone_object("players/ultramagnus/ring_power.c");
       move_object(ring, this_object());
}
}
ONE_EXIT("players/ultramagnus/btrail.c", "east",
       "Gollum's Hut",
       "A Disgusting stench is all about this dwelling. You\n" +
       "can hardly breath because of it.  There are many different\n" +
       "types of bones lying about...some animal....some human of elfish.\n" +
       "There are things scattered all about as if someone were trying\n" +
       "to find something.\n",0)
