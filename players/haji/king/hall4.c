#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("jester")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","jester");
       call_other(own,"set_short","Jester");
       call_other(own,"set_long","The court jester.\n");
       call_other(own,"set_ac",6);
       call_other(own,"set_wc",11);
       call_other(own,"set_hp",400);
       call_other(own,"set_level",7);
       call_other(own,"set_al",1);
       call_other(own,"set_chat_chance",23);
        call_other(own,"load_chat","Jester says:Why did the chicken cross the road?\n");
        call_other(own,"load_chat","Jester says:What is the meaning of life?\n");
        call_other(own,"load_chat","Jester says:What do you get when you cross an elephant and a rhinocerous?\n");
       move_object(own,this_object());
        wea=clone_object("players/haji/king/book.c");
         move_object(wea,own);
   }
 }
  FOUR_EXIT("players/haji/king/towent.c", "east",
            "players/haji/king/king1.c", "north",
            "players/haji/king/hall3.c", "south",
            "players/haji/king/prince1.c", "west",

    "A hallway",

      "This is a hallway,you get the feeling that\n" +
      "something very FUNNY is about.To the north\n" +
      "You see the throne room.To the east you see a\n" +
      "a stairway,to the west you see a room,and to \n" +
      "the south you see a hallway.\n",1)
  realm(){return "harem";}
