#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object sulu;
      if(!present("sulu")) {

        object jacket;
       sulu = clone_object("obj/monster");
       call_other(sulu, "set_id","sulu");
       call_other(sulu, "set_name", "sulu");
       call_other(sulu, "set_alt_name","sulu");
       call_other(sulu, "set_short", "Sulu is here");
       call_other(sulu, "set_ac", 13);
       call_other(sulu, "set_wc", 19);
       call_other(sulu, "set_long", "Sulu the lineless one\n");
       call_other(sulu, "set_level", 12);
       call_other(sulu, "set_al",60);
       call_other(sulu, "set_hp",250);
       call_other(sulu, "set_aggressive",0);
       call_other(sulu, "set_chat_chance",34);
       call_other(sulu, "load_chat","Sulu says: Please just give me one more thing to say besides yes,captain!\n");

       call_other(sulu, "load_chat","Sulu says: I only want to say an occasional line.\n");
       move_object(sulu, this_object());
       jacket = clone_object("players/rich/jacket");
       move_object(jacket,sulu);
    }
}



/*



*/


ONE_EXIT("players/rich/hall3u.c", "east",
   "Sulu`s Quarters",
            "This is Sulu`s quarters,in the corner you see a bed\n" +
             "on the wall you see a saber.\n",1)
realm(){return "enterprise";}
