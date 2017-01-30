#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
      "     Before you, a tangled mass of cypress trees seem to block\n"+
      "movement in all directions except that from whence you came.\n"+
      "You sense as though this particular area hasn't been traveled\n"+
      "in frequently in the past.\n");
   add_item("trees","The cypress trees block movement in any direction\n"+
      "except back to the east");
   add_item("mass","The cypress trees block movement in any direction\n"+
      "except back to the east");
   add_exit(ROOMS+"s20","east");
}
