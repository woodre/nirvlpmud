#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object harry;
    if(!present("harry")) {

        object money;
       harry = clone_object("obj/monster");
       call_other(harry, "set_id","harry");
       call_other(harry, "set_name", "harry mudd");
       call_other(harry, "set_alias", "harry");
       call_other(harry, "set_alt_name","mudd");
       call_other(harry, "set_short", "Harry Mudd is here.");
       call_other(harry, "set_ac", 1);
       call_other(harry, "set_long", "Harcourt Fenton Mudd\n");
       call_other(harry, "set_level", 2);
       call_other(harry, "set_al",-50);
       call_other(harry, "set_hp",60);
       call_other(harry, "set_wc",5);
       call_other(harry, "set_aggressive",1);
       call_other(harry, "set_chat_chance",30);
       call_other(harry, "load_chat","Harry says: I`m Harry Mudd Ruler of the Universe!\n");
       move_object(harry, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",20);
       move_object(money,harry);
    }
}



/*



*/


ONE_EXIT("players/rich/hall1.c", "west",
   "Visitor`s Quarters",
            "This is the visitor`s quarters.\n",1)
realm(){return "enterprise";}
