#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object borg;
    if(!present("borg")) {

        object money;
       borg = clone_object("obj/monster");
       call_other(borg, "set_id","borg");
       call_other(borg, "set_name", "a borg");
       call_other(borg, "set_alt_name","borg");
       call_other(borg, "set_short", "a borg");
       call_other(borg, "set_long", "a cybernetic organism out to kill you\n");
       call_other(borg, "set_ac", 13);
       call_other(borg, "set_level", 17);
       call_other(borg, "set_al",-80);
       call_other(borg, "set_hp",650);
       call_other(borg, "set_wc",30);
       call_other(borg, "set_chance",65);
       call_other(borg, "set_spell_mess2","The borg waves his hand and hits you with a fireball\n");
       call_other(borg, "set_spell_dam",60);
       call_other(borg, "set_aggressive",0);
       call_other(borg, "load_chat","Q says: pathetic human scum.\n");
move_object(borg,this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",(100+random(1000)));
       move_object(money,borg);
    }
}



/*



*/


ONE_EXIT("players/rich/lower/hall4d.c", "west",
	   "a room",
            "This is a room to the west a hallway",
           1)
realm(){return "enterprise";}
