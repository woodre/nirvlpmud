#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("shrubbery")) {
     own=clone_object("players/haji/quest/shrub.c");
       move_object(own,this_object());
   }
 }
  ONE_EXIT("players/haji/town/hermit2.c", "south",

    "A clearing",
      "This is a clearing you see a place for\n" +
      "a shrub in front of you.\n",1)
  realm(){return "harem";}
