#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("beggar")) {
        object arm;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","beggar");
       call_other(own,"set_short","Beggar");
       call_other(own,"set_long","A lowly beggar.\n");
       call_other(own,"set_ac",3);
       call_other(own,"set_wc",5);
       call_other(own,"set_level",3);
       call_other(own,"set_al",50);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Beggar says:Donations for the poor?\n");
       move_object(own,this_object());
        arm=clone_object("obj/armor");
         call_other(arm,"set_name","hat");
         call_other(arm,"set_short","a hat");
         call_other(arm,"set_long","a dirty hat");
         call_other(arm,"set_ac",1);
         call_other(arm,"set_value",50);
         call_other(arm,"set_weight",1);
         call_other(arm,"set_type","helmet");
         move_object(arm,own);
   }
 }
  FOUR_EXIT("players/haji/town/road1.c", "north",
            "players/haji/town/rogue1.c", "east",
            "players/haji/town/road3.c", "south",
            "players/haji/town/magic.c", "west",

    "A road in the middle of town.",
       "This is a road,to the north and south you see roads.\n" +
       "To the east you see an alley and to the west you\n" +
       "see Aladdin's Magic store.\n",1)
  realm(){return "harem";}
