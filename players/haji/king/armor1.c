#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
  extra_init() {
   add_action("look","look");
   add_action("look","exa");
   add_action("look","look at");
   }
ONE_EXIT("players/haji/king/hall3", "east",
   "Armory",
     "This is the armory,to the east you see a hall\n" +
     "before you you see a weapons locker.\n",1)
realm() {return "harem";}
look(str) {
   if (str=="locker"||str=="weapons locker") {
     write("You try to open the locker but it is locked!!!\n");
      return 1;
    }
  return 1;
 }
