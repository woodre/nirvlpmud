#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("assassin")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","assassin");
       call_other(own,"set_short","Assassin");
       call_other(own,"set_long","A stealthy assassin.\n");
       call_other(own,"set_ac",9);
       call_other(own,"set_wc",16);
       call_other(own,"set_hp",500);
       call_other(own,"set_level",14);
       call_other(own,"set_al",1);
       move_object(own,this_object());
        wea=clone_object("players/haji/king/sap.c");
         move_object(wea,own);
   }
 }
  ONE_EXIT("players/haji/king/hall2.c", "west",

    "A room",
       "This is a room,to the east you see\n" +
       "a hallway.\n",1)
  realm(){return "harem";}
