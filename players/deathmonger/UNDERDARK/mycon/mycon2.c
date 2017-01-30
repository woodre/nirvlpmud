
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
object mycon;
extra_reset(){
     if(!present("myconid")){
       mycon = clone_object("players/deathmonger/UNDERDARK/mycon/myconid");
       mycon->set_short("Fungus Boy");
       mycon->set_alias("boy");
       mycon->set_alt_name("fungus boy");
        move_object(mycon, this_object());
     }
}
TWO_EXIT("players/deathmonger/UNDERDARK/mycon/mycon1", "west",
         "players/deathmonger/UNDERDARK/mycon/mycon3", "east",
         "Myconid road",
         "As you stroll through the fungal town you don't ssee anyone\n"+
         "on the streets.  Myconids are a fearful bunch and don't like\n"+
         "to be seen, much less by the likes of you.\n", 1)
