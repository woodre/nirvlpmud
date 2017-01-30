
#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
     object sign;
     if(!present("sign")){
       sign = clone_object("players/deathmonger/MISC/maze_sign");
       move_object(sign, this_object());
     }
}
TWO_EXIT("players/deathmonger/UNDERDARK/tunnel15", "east",
         "players/deathmonger/UNDERDARK/maze/maze1", "west",
         "Entrance to Minotaur Maze",
         "This tunnel seems to have been cut a lot smoother than the\n"+
         "tunnels you've seen earlier.  There's something........\n"+
          "organized...even maze-like about it.\n"+
         "There is a something etched in the rocks on the left side\n", 0)

