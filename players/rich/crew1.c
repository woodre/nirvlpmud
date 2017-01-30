#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object crewman;
    if(!present("crewman")) {

        object money;
       crewman = clone_object("obj/monster");
       call_other(crewman, "set_id","crewman");
       call_other(crewman, "set_name", "crewman");
       call_other(crewman, "set_alt_name","crewman");
       call_other(crewman, "set_short", "a lowly crewman");
       call_other(crewman, "set_ac", 1);
       call_other(crewman, "set_long", "a lowly crewman\n");
       call_other(crewman, "set_level", 3);
       call_other(crewman, "set_al",100);
       call_other(crewman, "set_hp",75);
       call_other(crewman, "set_wc",5);
       call_other(crewman, "set_aggressive",0);
       move_object(crewman, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",50);
       move_object(money,crewman);
    }
}



/*



*/


ONE_EXIT("players/rich/hall1.c", "east",
   "Crewman`s Quarters",
            "This is a crewman`s quarters.\n",1)
realm(){return "enterprise";}
