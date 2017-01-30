#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object director;
    if(!present("director")) {

        object money;
       director = clone_object("obj/monster");
       call_other(director, "set_id","director");
       call_other(director, "set_name", "director");
       call_other(director, "set_alt_name","director");
       call_other(director, "set_short", "a old generation director");
       call_other(director, "set_ac", 3);
       call_other(director, "set_long", "a old generation director\n");
       call_other(director, "set_level", 7);
       call_other(director, "set_al",-100);
       call_other(director, "set_hp",150);
       call_other(director, "set_wc",10);
       call_other(director, "set_aggressive",1);
       move_object(director, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",200);
       move_object(money,director);
    }
}



/*



*/


FOUR_EXIT("players/rich/quest/lev23c.c", "east",
         "players/rich/quest/lev23a.c", "north",
         "players/rich/quest/lev24c.c", "south",
         "players/rich/hall3u.c", "west",
   "a room",
            "This is a room.\n",1)
realm(){return "NT";}
