#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object mccoy;
    if(!present("mccoy")) {

        object tricorder;
       mccoy = clone_object("obj/monster");
       call_other(mccoy, "set_id","mccoy");
       call_other(mccoy, "set_name", "mccoy");
       call_other(mccoy, "set_alt_name","bones");
       call_other(mccoy, "set_short", "mccoy is here.");
       call_other(mccoy, "set_ac", 16);
       call_other(mccoy, "set_wc", 23);
       call_other(mccoy, "set_long", "Leonard E. McCoy(country doctor)\n");
       call_other(mccoy, "set_al",60);
       call_other(mccoy, "set_hp",750);
       call_other(mccoy, "set_level", 18);
       call_other(mccoy, "set_aggressive",0);
       call_other(mccoy, "set_chat_chance",35);
       call_other(mccoy, "load_chat","Mccoy says: He`s dead Jim.\n");

       call_other(mccoy, "load_chat","Mccoy says: I`m a doctor not an engineer!!\n");
       call_other(mccoy, "load_chat","Mccoy says: That green blooded vulcan son of a bitch!!\n");
       call_other(mccoy, "load_chat","Mccoy says: I`m just a simple country doctor,Jim!\n");
call_other(mccoy,"load_chat","Mccoy says: It seems they`re bisexual reproducing at will,and boy do they have a lot of will!\n");
       move_object(mccoy, this_object());
       tricorder = clone_object("players/rich/ob.c");
       move_object(tricorder,mccoy);
    }
}



/*



*/


ONE_EXIT("players/rich/hall1u.c", "east",
   "CMO`s office",
            "You see a room that has a desk cluttered with " +
            "unfiled medical reports,in the corner you see\n" +
            "a locked cabinet containing various alcoholic "  +
            "drinks..\n",1)
realm(){return "enterprise";}
