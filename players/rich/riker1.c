#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object riker;
    if(!present("riker")) {

        object money;
       riker = clone_object("obj/monster");
       call_other(riker, "set_id","riker");
       call_other(riker, "set_name", "will riker");
       call_other(riker, "set_alt_name","riker");
       call_other(riker, "set_alias", "riker");
       call_other(riker, "set_short", "Riker is here.");
       call_other(riker, "set_ac", 13);
       call_other(riker, "set_long", "William T. Riker\n");
       call_other(riker, "set_level", 13);
       call_other(riker, "set_al",70);
       call_other(riker, "set_hp",275);
       call_other(riker, "set_wc",17);
       call_other(riker, "set_aggressive",0);
       call_other(riker, "set_chat_chance",22);
       call_other(riker, "load_chat","Riker says: What the hell!!!\n");
       call_other(riker, "load_chat","Riker says: Who the hell!!!\n");
       call_other(riker, "load_chat","Riker says: Watch out or I`ll snap you back" +
                    " so fast you`ll think that " +
                    "you`re a first year cadet!!!\n");

       move_object(riker, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",1001);
       move_object(money,riker);
    }
}



/*



*/


ONE_EXIT("players/rich/hall4.c", "west",
   "Riker`s Quarters",
            "This is Will Riker`s quarters,you see various plants about the room.\n" +
            "To the west you see a hallway.\n",1)
realm(){return "enterprise";}
