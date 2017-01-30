#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object smurf;
    if(!present("smurf")) {

        object money;
       smurf = clone_object("obj/monster");
       call_other(smurf, "set_id","smurf");
       call_other(smurf,"set_name","papa smurf");
       call_other(smurf, "set_alt_name","smurf");
       call_other(smurf, "set_short", "Papa Smurf is here.");
       call_other(smurf, "set_ac", 10);
       call_other(smurf, "set_wc", 16);
       call_other(smurf, "set_long", "Papa Smurf a little blue man with a white beard.\n");
       call_other(smurf, "set_level", 12);
       call_other(smurf, "set_al",67);
       call_other(smurf, "set_hp",250);
       call_other(smurf, "set_aggressive",0);
       call_other(smurf, "set_chat_chance",45);
      call_other(smurf, "load_chat","Papa Smurf says: Where am I,have you seen my village?\n");
      call_other(smurf, "load_chat","Papa Smurf sings: la la  la  la la la\n");
      call_other(smurf, "load_chat","Papa Smurf says: Oh no!!Does this mean I`m in syndication now?\n");

       move_object(smurf, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",1001);
       move_object(money,smurf);
    }
}



/*



*/


ONE_EXIT("players/rich/hall4u.c", "east",
   "The Armory",
            "This is the armory,on the walls you see many\n" +
            "different types of weapons.\n" +
            "You get the feeling of something good but\n" +
            "confused is lying about.\n" ,
               1)
realm(){return "enterprise";}
