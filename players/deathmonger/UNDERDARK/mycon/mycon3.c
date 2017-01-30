
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
object mycon;
extra_reset(){
     if(!present("myconid")){
       mycon = clone_object("players/deathmonger/UNDERDARK/mycon/myconid");
       mycon->set_short("Fungus Boy");
       mycon->set_alias("boy");
        move_object(mycon, this_object());
     }
}
TWO_EXIT("players/deathmonger/UNDERDARK/mycon/mycon2", "west",
         "players/deathmonger/UNDERDARK/mycon/hut", "east",
         "Myconid road",
         "You stand before a hut that you interpret to be the home of the\n"+
         "mayor of the town.\n",
         1)
