#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("hermit")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","hermit");
       call_other(own,"set_short","Hermit");
       call_other(own,"set_long","A lonely hermit.\n");
       call_other(own,"set_ac",4);
       call_other(own,"set_wc",7);
       call_other(own,"set_level",3);
       call_other(own,"set_hp",80);
       call_other(own,"set_al",50);
       call_other(own,"set_aggressive",1);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Hermit says:Leave me alone!!!!!\n");
       move_object(own,this_object());
        wea=clone_object("obj/weapon");
         call_other(wea,"set_name","staff");
         call_other(wea,"set_short","a knarled staff");
         call_other(wea,"set_long","a really knarled staff");
         call_other(wea,"set_class",6);
         call_other(wea,"set_value",125);
         call_other(wea,"set_weight",2);
         move_object(wea,own);
   }
 }
  ONE_EXIT("players/haji/town/hermit2.c", "east",

    "A hut",
      "This is a hut,to the east you see a clearing.\n",1)
  realm(){return "harem";}
