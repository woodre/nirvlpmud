#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("robber")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","robber");
       call_other(own,"set_short","Robber");
       call_other(own,"set_long","A sneaky robber.\n");
       call_other(own,"set_ac",5);
       call_other(own,"set_wc",8);
       call_other(own,"set_level",4);
       call_other(own,"set_hp",99);
       call_other(own,"set_al",50);
       call_other(own,"set_aggressive",1);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Robber says:Stick em' up!!!!\n");
       move_object(own,this_object());
        wea=clone_object("obj/weapon");
         call_other(wea,"set_name","sword");
         call_other(wea,"set_short","a sword");
         call_other(wea,"set_long","a small sword");
         call_other(wea,"set_class",7);
         call_other(wea,"set_value",175);
         call_other(wea,"set_weight",2);
         move_object(wea,own);
   }
 }
  TWO_EXIT("players/haji/town/forest1.c", "north",
           "players/haji/town/forest3.c", "south",

    "A dark forest",
       "This is a forest,to the north the forest\n" +
       "thins and to the south you see a fork in \n" +
       "road.\n",1)
  realm(){return "harem";}
