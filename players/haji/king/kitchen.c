#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("chef")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","chef");
       call_other(own,"set_short","Chef");
       call_other(own,"set_long","The king's chef.\n");
       call_other(own,"set_ac",6);
       call_other(own,"set_wc",10);
       call_other(own,"set_level",9);
       call_other(own,"set_hp",150);
       call_other(own,"set_al",50);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Chef says:What do you want to eat?\n");
       move_object(own,this_object());
        wea=clone_object("obj/weapon");
         call_other(wea,"set_name","pin");
         call_other(wea,"set_short","a rolling pin");
         call_other(wea,"set_long","a chef's rolling pin");
         call_other(wea,"set_class",11);
         call_other(wea,"set_value",300);
         call_other(wea,"set_weight",2);
         move_object(wea,own);
   }
 }
  ONE_EXIT("players/haji/king/dinhall1.c", "east",

    "The kitchen",
        "This is the kitchen.Around you you see the\n" +
        "various implements for your standard kitchen.\n" +
        "To the east is the dining hall.\n",1)
  realm(){return "harem";}
