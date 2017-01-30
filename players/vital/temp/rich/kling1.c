#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object klingon;
    if(!present("klingon")) {

        object money;
       klingon = clone_object("obj/monster");
       call_other(klingon, "set_id","klingon");
       call_other(klingon, "set_name", "klingon");
       call_other(klingon, "set_alt_name","klingon");
       call_other(klingon, "set_short", "a klingon is here");
       call_other(klingon, "set_ac", 1);
       call_other(klingon, "set_long", "a klingon of the lower ranks\n");
       call_other(klingon, "set_level", 3);
       call_other(klingon, "set_al",-100);
       call_other(klingon, "set_hp",75);
       call_other(klingon, "set_wc",7);
       call_other(klingon, "set_aggressive",1);
       call_other(klingon, "set_chat_chance",30);
       call_other(klingon, "load_chat","Klingon says: Die!!!You lowly human scum!!!!\n");
       move_object(klingon, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",50);
       move_object(money,klingon);
    }
}



/*



*/


ONE_EXIT("players/rich/hall2.c", "west",
   "Visitor`s Quarters",
            "This is the visitor`s quarters.\n",1)
realm(){return "enterprise";}
