#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object crusher;
    if(!present("crusher")) {

        object money;
       crusher = clone_object("obj/monster");
       call_other(crusher, "set_id","crusher");
       call_other(crusher, "set_name", "crusher");
       call_other(crusher, "set_alt_name","beverly");
       call_other(crusher, "set_short", "Dr. Crusher is here");
       call_other(crusher, "set_ac", 13);
       call_other(crusher, "set_wc", 19);
       call_other(crusher, "set_long", "Dr. Beverly Crusher\n");
       call_other(crusher, "set_level", 12);
       call_other(crusher, "set_al",60);
       call_other(crusher, "set_hp",250);
       call_other(crusher, "set_aggressive",0);
       call_other(crusher, "set_chat_chance",35);
       call_other(crusher, "load_chat","Dr. Crusher says: OOOHHH Jean-Luc!!!.\n");

       call_other(crusher, "load_chat","Dr. Crusher says: What have you done with my son!!\n");
       move_object(crusher, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",1001);
       move_object(money,crusher);
    }
}



/*



*/


ONE_EXIT("players/rich/hall1u.c", "west",
   "Officer`s Quarters",
            "This is Dr. Beverly Crushers quarters.\n",1)
realm(){return "enterprise";}
