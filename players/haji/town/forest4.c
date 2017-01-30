#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("wolf")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","wolf");
       call_other(own,"set_short","Wolf");
       call_other(own,"set_long","The Big Bad Wolf.\n");
       call_other(own,"set_ac",5);
       call_other(own,"set_wc",8);
       call_other(own,"set_level",4);
       call_other(own,"set_hp",99);
       call_other(own,"set_al",50);
       call_other(own,"set_aggressive",1);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Wolf says:I'll huff and puff and blow your house down!!!!\n");
       call_other(own,"load_chat","Wolf says:Where's Grandma?\n");
       call_other(own,"load_chat","Wolf says:Here little red riding hood!!!\n");
       move_object(own,this_object());
        wea=clone_object("obj/weapon");
         call_other(wea,"set_name","teeth");
         call_other(wea,"set_short","some teeth");
         call_other(wea,"set_long","wolf's teeth");
         call_other(wea,"set_class",7);
         call_other(wea,"set_value",175);
         call_other(wea,"set_weight",2);
         move_object(wea,own);
   }
 }
  TWO_EXIT("players/haji/town/forest3.c", "north",
           "players/haji/town/forest5.c", "south",

    "A dark forest",
       "This is a forest, to the north the forest\n" +
       "splits into a fork.  To the south the forest\n" +
       "begins to thin.\n",1)
  realm(){return "harem";}
