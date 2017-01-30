#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("queen")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","queen");
       call_other(own,"set_short","Queen");
       call_other(own,"set_long","The regal queen.\n");
       call_other(own,"set_ac",5);
       call_other(own,"set_wc",12);
       call_other(own,"set_hp",350);
       call_other(own,"set_level",10);
       call_other(own,"set_al",1);
       move_object(own,this_object());
        wea=clone_object("players/haji/king/cbelt.c");
         move_object(wea,own);
   }
 }
  ONE_EXIT("players/haji/king/king1.c", "south",

    "The Queen's room",
       "This is the queen's room,this is\n" +
       "where the king goes when he wants \n" +
       "to relax,to the south you see the \n" +
       "throne room.\n",1)
  realm(){return "harem";}
