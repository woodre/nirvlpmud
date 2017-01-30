#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();


object myconid;
extra_reset(){
if(!myconid){
     myconid = clone_object("players/deathmonger/UNDERDARK/mycon/myconid");
     myconid->set_short("A myconid guard");
     move_object(myconid, this_object());
}
}

TWO_EXIT("players/deathmonger/UNDERDARK/mycon/mycon1","east",
        "players/deathmonger/UNDERDARK/tunnel9b","west",
        "Entrance to Myconid town",
        "You stand at the entrance to a peculiar looking town inside\n"+
        "a great cavern.  The ceiling of the cavern is about 1000 feet\n"+
        "high and it stretches for about a mile. The inhabitants are white\n"+
        "mushroom-like creatures of a type you have never seen before. They\n"+
        "appear to be intelligent, but as they look at you, they run away\n"+
        "in fright. What a curious place!\n", 1)
