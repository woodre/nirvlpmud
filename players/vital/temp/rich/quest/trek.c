#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object trekkie;
    if(!present("trekkie")) {

        object money;
       trekkie = clone_object("obj/monster");
       call_other(trekkie, "set_id","trekkie");
       call_other(trekkie, "set_name", "trekkie");
       call_other(trekkie, "set_alt_name","trekkie");
       call_other(trekkie, "set_short", "a new generation trekkie");
       call_other(trekkie, "set_ac", 1);
       call_other(trekkie, "set_long", "a new generation trekkie\n");
       call_other(trekkie, "set_level", 3);
       call_other(trekkie, "set_al",100);
       call_other(trekkie, "set_hp",75);
       call_other(trekkie, "set_wc",5);
       call_other(trekkie, "set_aggressive",1);
       move_object(trekkie, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",50);
       move_object(money,trekkie);
    }
}



/*



*/


TWO_EXIT("players/rich/quest/room.c", "east",
         "players/rich/quest/room.c", "north",
   "a room",
            "This is a room.\n",1)
