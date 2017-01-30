#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object tarr;
    if(!present("tarr")) {

        object whip,w_hit_whip;
       tarr = clone_object("obj/monster");
       call_other(tarr, "set_id","tarr");
       call_other(tarr, "set_name", "Daimon Tarr.");
       call_other(tarr, "set_alt_name","tarr");
       call_other(tarr, "set_short", "Daimon Tarr");
       call_other(tarr, "set_long", "Daimon Tarr"); 
       call_other(tarr, "set_ac", 11);
       call_other(tarr, "set_wc",18);
       call_other(tarr, "set_level", 16);
       call_other(tarr, "set_al",-75);
       call_other(tarr, "set_hp",450);
       call_other(tarr, "set_spell_mess2","Tarr waves his hand and hits you with a fireball\n");
       call_other(tarr, "set_chance",40);
       call_other(tarr, "set_spell_dam",30);
       call_other(tarr, "set_aggressive",0);
       call_other(tarr, "set_chat_chance",40);
       call_other(tarr, "load_chat","Tarr says: pathetic human scum.\n");
       call_other(tarr, "load_chat","Tarr says: you clothe your women!!\n");
move_object(tarr,this_object());
       whip = clone_object("obj/weapon");
       w_hit_whip=clone_object("players/rich/w_hit_whip.c");
         call_other(whip,"set_name","electric whip");
         call_other(whip,"set_class",8);
         call_other(whip,"set_weight",3);
         call_other(whip,"set_value",650);
         call_other(whip,"set_alias","whip");
         call_other(whip,"set_short","Electric Whip");
         call_other(whip,"set_long","A Thringi electric whip.\n");
         call_other(whip,"set_hit_func",w_hit_whip);
       move_object(whip,tarr);
    }
}



/*


*/





ONE_EXIT("players/rich/hall4u.c", "west",
	   "a room",
           "This is a room.\n",
           1)
realm(){return "enterprise";}
