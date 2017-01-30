#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
      "     Before you, a tangled mass of cypress trees seem to block movement\n"
      +"in all directions except that from whence you came.  You sense as though\n"
      +"this particular area hasn't been traveled in frequently in the past.\n");
   add_item(({"mass","trees","cypress trees"}),
      "The cypress trees block movement in any direction\n"+
      " except back to the south");
   remove_property("NT");
   add_exit(ROOMS+"s14","south");
}
