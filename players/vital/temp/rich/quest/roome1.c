#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
object wesley;

extra_reset(){

    if(!present("wesley")) {

        object money;
       wesley = clone_object("obj/monster");
       call_other(wesley, "set_id","wesley");
       call_other(wesley, "set_name", "wesley");
       call_other(wesley, "set_alias", "wesley");
       call_other(wesley, "set_alt_name","whiny");
       call_other(wesley, "set_short", "Wesley Crusher is here.");
       call_other(wesley, "set_ac", 2);
       call_other(wesley, "set_long", "Wesley (the whiny one) Crusher\n");
       call_other(wesley, "set_level", 5);
       call_other(wesley, "set_al",50);
       call_other(wesley, "set_hp",100);
       call_other(wesley, "set_wc",8);
       call_other(wesley, "set_aggressive",0);
       call_other(wesley, "set_chat_chance",50);
       call_other(wesley, "load_chat","Wesley says: waaaaaahhhh, i want to be an occifer!!!\n");
       call_other(wesley, "load_chat","Wesley says: waaaahhhh,I want my mommeee!!!!\n");
       call_other(wesley, "load_chat","Wesley says: I know ALL the answers,but can you tie my shoes for me?\n");
       move_object(wesley, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",125);
       move_object(money,wesley);
    }
}



/*



*/


TWO_EXIT("players/rich/quest/hall1.c", "west",
          "players/rich/quest/roome2.c", "north",
            "a room",
            "This is a hallway.To the north is a room,to the west is a hall.\n" ,
                 1)
realm(){return "enterprise";}
