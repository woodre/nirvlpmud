#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object data;
    if(!present("data")) {

        object arm;
       data = clone_object("obj/monster");
       call_other(data, "set_id","data");
       call_other(data, "set_name", "data");
       call_other(data, "set_alt_name","data");
       call_other(data, "set_short", "Data is here.");
       call_other(data, "set_ac", 13);
       call_other(data, "set_wc", 19);
       call_other(data, "set_long", "Data the android\n");
       call_other(data, "set_level", 12);
       call_other(data, "set_al",65);
       call_other(data, "set_hp",250);
       call_other(data, "set_aggressive",0);
       call_other(data, "set_chat_chance",25);
      call_other(data, "load_chat","Data says: I am fully functional in EVERY way.\n");

       call_other(data, "load_chat","Data says: I only want to be human.\n");
       move_object(data, this_object());
       arm = clone_object("players/rich/bodarm.c");
       call_other(arm, "set_arm",1001);
       move_object(arm,data);
    }
}



/*



*/


ONE_EXIT("players/rich/hall3.c", "east",
   "Data`s laboratory",
            "This is Data`s lab,you see computers along the wall " +
            "and a workbench in the \n" +
            "center.\n",1)
realm(){return "enterprise";}
