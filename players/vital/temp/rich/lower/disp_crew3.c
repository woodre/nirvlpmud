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
       call_other(crewman, "set_short", "The disposable crewman is here");
       call_other(crewman, "set_ac", 1);
       call_other(crewman, "set_long", "The Disposable Crewman\n");
       call_other(crewman, "set_level", 3);
       call_other(crewman, "set_al",100);
       call_other(crewman, "set_hp",75);
       call_other(crewman, "set_wc",5);
       call_other(crewman, "set_aggressive",0);
       call_other(crewman, "set_chat_chance",90);
       call_other(crewman, "load_chat","Ensign Schmedlack says: Hi I`m the disposable crewman,\n" +
                  "please let me fill my purpose by killing me.\n");
       move_object(crewman, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",50);
       move_object(money,crewman);
    }
}



/*



*/


ONE_EXIT("players/rich/lower/hall3d.c", "west",
   "Crewman`s Quarters",
            "This is a crewman`s quarters.To the east is a hallway.\n",1)
realm(){return "enterprise";}
