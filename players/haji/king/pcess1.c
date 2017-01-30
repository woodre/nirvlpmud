#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("princess")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","princess");
       call_other(own,"set_short","Princess");
       call_other(own,"set_long","The dainty princess.\n");
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
  ONE_EXIT("players/haji/king/hall3.c", "west",

    "The room of the king's princess.",
       "This is the princess's room,to the west\n" +
       "you see a hallway.\n",1)
  realm(){return "harem";}
