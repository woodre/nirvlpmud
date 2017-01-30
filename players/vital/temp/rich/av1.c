#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object harry;
    if(!harry || !living(harry)){

        object money;
       harry = clone_object("obj/monster");
       call_other(harry, "set_id","harry");
       call_other(harry, "set_name", "harry mudd");
       call_other(harry, "set_alt_name","mudd");
       call_other(harry, "set_short", "Harry Mudd is here.");
       call_other(harry, "set_ac", 10);
       call_other(harry, "set_long", "Harcourt Fenton Mudd\n");
       call_other(harry, "set_level", 2);
       call_other(harry, "set_al",250);
       call_other(harry, "set_ex",1000);
       call_other(harry, "set_hp",250);
       call_other(harry, "set_wc",10);
       call_other(harry, "set_spell_mess1","Harry casts a fireball\n");
       call_other(harry, "set_spell_mess2","Harry hits you with a fireball\n");
       call_other(harry, "set_chance",90);
       call_other(harry, "set_spell_dam",40);
       call_other(harry, "set_aggressive",0);
       call_other(harry, "set_chat_chance",30);
       call_other(harry, "load_chat","Harry says: Do I know you?\n");
       call_other(harry, "load_chat","Harry says: Have you seen my keys?\n");
       call_other(harry, "load_chat","Harry says: I haven't seen you in ages!\n");
       call_other(harry, "load_chat","Harry says: Make yourself at home\n");
       call_other(harry, "load_chat","Harry says: Hey, I got a new AV system.\n");
       call_other(harry, "load_chat","Harry says: Charles, bring us refreshments!\n");
       call_other(harry, "load_chat","Harry says: 'Toni' is here, I always knew " +
       "he was a little strange.\n");
       call_other(harry, "load_chat","Harry says: So how long will you be staying?\n");
       call_other(harry, "load_chat","Do you know the elements?\n");
       call_other(harry, "load_chat","earth......\n");
       call_other(harry, "set_move_at_reset",1);
       move_object(harry, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",(1000+random(1000)));
       move_object(money,harry);
    }
}



/*



*/


TWO_EXIT("players/harry/room/av3.c", "south",
	   "players/harry/room/av2.c", "east",
	   "av room",
            "This is the northwest corner of the Audio Visual room " +
            "to the south you see\n" +
            "all of the major equipment.  On the walls you see more " +
            "tapestries\n" +
            "There's something strange about them.\n",
           1)
