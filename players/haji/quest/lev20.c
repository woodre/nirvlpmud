#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
  extra_init() {
   object ob;
   string str;
     str="branch";
    ob=this_player();
   if(!present(str,ob)) {
     write("You dont have a branch go back and get one to continue.\n");
     move_object(ob,"players/haji/e1.c");
    return 1;
  }
 return 1;
 }
ONE_EXIT("players/haji/quest/lev21.c", "north",
  "A forest",
     "You see the forest begin to thin towards the north.\n",1)
