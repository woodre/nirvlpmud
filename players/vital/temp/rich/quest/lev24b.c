#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object kirk;
    if(!present("kirk")) {

        object money;
       kirk = clone_object("obj/monster");
       call_other(kirk, "set_id","kirk");
       call_other(kirk, "set_name", "captain kirk");
       call_other(kirk, "set_alt_name","kirk");
       call_other(kirk, "set_short", "Captain Kirk");
       call_other(kirk, "set_long", "Captain James T. Kirk"); 
       call_other(kirk, "set_ac", 8);
       call_other(kirk, "set_level", 16);
       call_other(kirk, "set_al",500);
       call_other(kirk, "set_hp",450);
       call_other(kirk, "set_wc",15);
       call_other(kirk, "set_spell_mess1","he shoots you with a phuzzer!!!\n");
       call_other(kirk, "set_chance",29);
       call_other(kirk, "set_spell_dam",28);
       call_other(kirk, "set_aggressive",1);
       call_other(kirk, "set_chat_chance",40);
      call_other(kirk,"load_chat","I`M the REAL captain of the Enterprise!!!\n");
     call_other(kirk,"load_chat","Captain Picard is a wimpy french freak!!\n");
move_object(kirk,this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",(750+random(1000)));
       move_object(money,kirk);
    }
}



/*



*/


FOUR_EXIT("players/rich/hall5u.c", "south",
          "players/rich/quest/lev24c.c", "east",
          "players/rich/quest/lev24a.c", "north",
          "players/rich/quest/lev21a.c", "down",
	   "a room",
            "This is a room to the south a hallway",
           1)
realm(){return "NT";}
