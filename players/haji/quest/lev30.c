#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
  extra_init() {
   object ob;
   string str;
     str="diary1";
    ob=this_player();
   if(!present(str,ob)) {
     write("You dont have a diary go back and get one to continue.\n");
     move_object(ob,"players/haji/e1.c");
    return 1;
  }
 return 1;
 }
TWO_EXIT("players/haji/quest/lev31.c", "east",
         "players/haji/quest/hitler.c", "south",
  "A room",
    "This is an immense room,you see a path towards the north.\n",1)
