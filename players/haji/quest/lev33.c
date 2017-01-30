#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
   add_action("toss","toss");
   }
  ONE_EXIT("players/haji/quest/h1.c", "south",

   "A long chasm",
      "This is a chasm you see before you\n" +
      "a pile of sand,you get the urge to toss it.\n",1)
  realm(){return "harem";}
toss(str) {
     if(str=="sand") {
       write("You toss the sand see a bridge form..\n");
       write("and you move across the bridge.\n");
     move_object(this_player(),"players/haji/quest/lev34.c");
  return 1;
  }

  return 1;
 }


