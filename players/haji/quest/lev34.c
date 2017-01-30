#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("knight")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","knight");
       call_other(own,"set_short","Brave Knight");
       call_other(own,"set_long","a very old knight.\n");
       call_other(own,"set_ac",10);
       call_other(own,"set_wc",12);
       call_other(own,"set_alias","brave knight");
       call_other(own,"set_level",10);
       call_other(own,"set_hp",450);
       call_other(own,"set_al",50);
       call_other(own,"set_aggressive",1);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Knight says: You must get my key to solve your quest.\n");
       move_object(own,this_object());
        wea=clone_object("players/haji/quest/gkey.c");
        move_object(wea,own);
   }
 }
  TWO_EXIT("players/haji/quest/lev33.c", "east",
           "players/haji/quest/lev40.c", "north",

    "A glowing room",
      "This is a room,to the north you see a light\n" +
      "emanating from the doorway.\n",1)
  realm(){return "harem";}
