#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("rogue")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","rogue");
       call_other(own,"set_short","Rogue");
       call_other(own,"set_long","A sneaky rogue.\n");
       call_other(own,"set_ac",5);
       call_other(own,"set_wc",8);
       call_other(own,"set_level",4);
       call_other(own,"set_hp",99);
       call_other(own,"set_al",50);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Rogue says:Go away!!!!\n");
       move_object(own,this_object());
        wea=clone_object("obj/weapon");
         call_other(wea,"set_name","sword");
         call_other(wea,"set_short","a sword");
         call_other(wea,"set_long","a small sword");
         call_other(wea,"set_class",1);
         call_other(wea,"set_value",175);
         call_other(wea,"set_weight",2);
         move_object(wea,own);
   }
 }
  ONE_EXIT("players/haji/town/road2.c", "west",

    "A dark alley",
       "This is a dark alley,to the east\n" +
       "you see a road.\n",1)
  realm(){return "harem";}
