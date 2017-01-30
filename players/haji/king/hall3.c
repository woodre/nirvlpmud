#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("guard")) {
        object wea,arm;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","guard");
       call_other(own,"set_short","Guard");
       call_other(own,"set_long","The king's guard.\n");
       call_other(own,"set_ac",11);
       call_other(own,"set_wc",18);
       call_other(own,"set_hp",650);
       call_other(own,"set_level",15);
       call_other(own,"set_al",1);
       call_other(own,"set_aggressive",1);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Guard growls:You'll not get past me!!!!\n");
       move_object(own,this_object());
        wea=clone_object("players/haji/king/gwep.c");
         move_object(wea,own);
        arm=clone_object("players/haji/king/garm.c");
         move_object(arm,own);
   }
 }
  FOUR_EXIT("players/haji/king/hall2.c", "south",
            "players/haji/king/hall4.c", "north",
            "players/haji/king/armor1.c", "west",
            "players/haji/king/pcess1.c", "east",

     "A hallway",
       "This is a hallway,to the east is a room.\n" +
       "To the west you see the armory.\n" +
       "To the north and south are halls.\n",1)
  realm(){return "harem";}
