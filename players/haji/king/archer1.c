#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("archer")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","archer");
       call_other(own,"set_short","Archer");
       call_other(own,"set_long","The mighty archer.\n");
       call_other(own,"set_ac",11);
       call_other(own,"set_wc",19);
       call_other(own,"set_hp",700);
       call_other(own,"set_level",16);
       call_other(own,"set_al",1);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Archer says:My weapon can strike at a distance!!!\n");
       move_object(own,this_object());
        wea=clone_object("players/haji/king/bow.c");
         move_object(wea,own);
   }
 }
  ONE_EXIT("players/haji/king/hall2.c", "east",

    "The room of the king's archer.",
       "This is the archer's room,to the east\n" +
       "you see a hallway.\n",1)
  realm(){return "harem";}
