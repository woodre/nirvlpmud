#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("prince")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","prince");
       call_other(own,"set_short","Prince");
       call_other(own,"set_long","The impatient prince.\n");
       call_other(own,"set_ac",4);
       call_other(own,"set_wc",13);
       call_other(own,"set_hp",400);
       call_other(own,"set_level",11);
       call_other(own,"set_al",1);
       move_object(own,this_object());
        wea=clone_object("obj/money");
         call_other(wea,"set_money",600);
         move_object(wea,own);
   }
 }
  ONE_EXIT("players/haji/king/hall4.c", "east",

    "The room of the king's prince.",
       "This is the prince's room,to the west\n" +
       "you see a hallway.\n",1)
  realm(){return "harem";}