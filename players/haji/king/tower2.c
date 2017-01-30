#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
   add_action("look","look");
   add_action("look","exa");
   }
  ONE_EXIT("players/haji/king/tower1.c", "down",

    "Top of the tower",
       "This is the top of the tower.\n" +
       "Before you you see a window.\n",1)
  realm(){return "harem";}
look(str) {
   if(str=="window"||str=="out") {
    write("You look out the window.\n");
    write("It is a very pictureseque view.\n");
    write("To the south you see a forest,\n");
    write("to the far south you see a town.\n");
    write("to the east you see a harem,\n");
    write("and to the north you see a gate.\n");
    return 1;
    }
  return 1;
 }
