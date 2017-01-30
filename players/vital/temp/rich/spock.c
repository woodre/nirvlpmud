#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object spock;
    if(!spock || !living(spock)){

        object money;
       spock = clone_object("obj/monster");
       call_other(spock, "set_id","spock");
       call_other(spock, "set_name", "Spock the logical one.");
       call_other(spock, "set_alt_name","spock");
       call_other(spock, "set_short", "Spock the logical one");
       call_other(spock, "set_long", "Spock the logical one"); 
       call_other(spock, "set_ac", 7);
       call_other(spock, "set_level", 14);
       call_other(spock, "set_al",450);
       call_other(spock, "set_hp",350);
       call_other(spock, "set_wc",15);
       call_other(spock, "set_spell_mess1","Spock pokes you with the point of his ears\n");
       call_other(spock, "set_spell_mess2","Spock says peace and long life as he pounds you to bits\n");
       call_other(spock, "set_chance",65);
       call_other(spock, "set_spell_dam",28);
       call_other(spock, "set_aggressive",0);
       call_other(spock, "set_chat_chance",40);
       call_other(spock, "load_chat","that is illogical.\n");
       call_other(spock, "load_chat","I have no emotions\n");
       call_other(spock, "load_chat","leave my ears alone\n");
       money = clone_object("obj/money");
       call_other(money, "set_money",(1000+random(1000)));
       move_object(money,spock);
    }
}



/*



*/


ONE_EXIT("players/rich/hall2u.c", "west",
	   "a room",
            "This is a room to the west a hallway",
           1)
