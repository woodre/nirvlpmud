
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

THREE_EXIT("players/deathmonger/UNDERDARK/maze/maze6a", "south",
         "players/deathmonger/UNDERDARK/maze/maze7", "north",
         "players/deathmonger/UNDERDARK/maze/maze5", "west",
         "Arrrgh! But fortunately not a maze",
         "Oh, no, you've lost your bearings in this strange tunnel!\n"+
         "But things could be worse...you could be in a maze with a \n"+
         "minotaur in it or something.\n", 0)
