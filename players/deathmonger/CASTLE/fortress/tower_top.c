
#include "std.h"

#undef EXTRA_RESET
#undef EXTRA_INIT
#define EXTRA_RESET extra_reset();
#define EXTRA_INIT extra_init();

object high, dude;
extra_reset(){
     if(!present("highlander")){
       high = clone_object("players/deathmonger/MONSTERS/highlander");
       move_object(high, this_object());
     }
}

extra_init(){
     dude = this_player();
}
query_dude(){ return dude; }

ONE_EXIT("players/deathmonger/CASTLE/fortress/tower2", "down",
         "Highlander's prison",
         "Here sits a lonely individual in s single chair that sits in \n"+
         "a bare room atop the tower.  He is the Highlander, imprisoned\n"+
         "by Demogorgon long ago.\n", 1)
