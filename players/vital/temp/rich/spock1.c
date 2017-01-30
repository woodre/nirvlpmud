#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object spock;
    if(!present("spock")) {

        object armor;
       spock = clone_object("obj/monster");
       call_other(spock, "set_id","spock");
       call_other(spock, "set_name", "Spock the logical one.");
       call_other(spock, "set_alias","spock");
       call_other(spock, "set_short", "Spock the logical one");
       call_other(spock, "set_long", "Spock the logical one"); 
       call_other(spock, "set_ac", 14);
       call_other(spock, "set_wc", 20);
       call_other(spock, "set_level", 14);
       call_other(spock, "set_al",73);
       call_other(spock, "set_hp",350);
       call_other(spock, "set_spell_mess1","Spock pokes you with the point of his ears\n");
       call_other(spock, "set_spell_mess2","Spock says peace and long life as he pounds you to bits\n");
       call_other(spock, "set_chance",55);
       call_other(spock, "set_spell_dam",30);
       call_other(spock, "set_aggressive",0);
       move_object(spock,this_object());
       call_other(spock, "set_chat_chance",40);
       call_other(spock, "load_chat","Spock says: that is illogical.\n");
       call_other(spock, "load_chat","Spock says: I have no emotions\n");
       call_other(spock, "load_chat","Spock says: leave my ears alone\n");
       armor = clone_object("players/rich/protector.c");
       move_object(armor,spock);
    }
}



/*



*/


ONE_EXIT("players/rich/hall2u.c", "west",
   "Spock`s Quarters",
            "This is Spock`s quarters you see a bed " +
            "in one corner,a stone bench in another\n" +
            "and a glowing pot in another corner.\n" ,
           1)
realm(){return "enterprise";}
