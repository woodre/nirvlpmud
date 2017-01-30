#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("jones")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","jones");
       call_other(own,"set_short","Henry Jones");
       call_other(own,"set_long","Henry Jones anthropologist.\n");
       call_other(own,"set_ac",10);
       call_other(own,"set_wc",12);
       call_other(own,"set_level",10);
       call_other(own,"set_hp",450);
       call_other(own,"set_al",50);
       call_other(own,"set_aggressive",1);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Henry Jones says:Leave me alone!!!!!\n");
       move_object(own,this_object());
        wea=clone_object("players/haji/quest/diary.c");
        move_object(wea,own);
   }
 }
  TWO_EXIT("players/haji/quest/lev17.c", "east",
           "players/haji/quest/lev19.c", "north",

    "A forest",
      "This is a forest,to the east you see a forest and west a forest.\n",1)
  realm(){return "harem";}
