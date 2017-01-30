#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object organian;
    if(!present("organian")) {

        object money;
       organian = clone_object("obj/monster");
       call_other(organian, "set_id","organian");
       call_other(organian, "set_name", "organian");
       call_other(organian, "set_alt_name","organian");
       call_other(organian, "set_short", "an Organian(real powerful) is here.");
       call_other(organian, "set_ac", 13);
       call_other(organian, "set_wc", 23);
       call_other(organian, "set_long", "an All-Powerful Organian\n");
       call_other(organian, "set_level", 19);
       call_other(organian, "set_al",100);
       call_other(organian, "set_hp",600);
       call_other(organian, "set_spell_mess1","The Organian casts a fireball\n");
       call_other(organian, "set_spell_mess2","The Organian hits you with a fireball\n");
       call_other(organian, "set_chance",90);
       call_other(organian, "set_spell_dam",35);
       call_other(organian, "set_aggressive",0);
       move_object(organian, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",(1000+random(1000)));
       move_object(money,organian);
    }
}



/*



*/


ONE_EXIT("players/rich/hall3.c", "west",
	   "a room",
            "This is a very bright room(because of the organian) " +
            ".\n",
           1)
realm(){return "enterprise";}
