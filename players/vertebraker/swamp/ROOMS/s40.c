#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
      "     Here the path branches off to the southeast and to the west.\n"
      +"Though there is dense fog, you can make out some sort of light source\n"
      +"coming from the southeast direction, but you are not certain what\n"
      +"it may be.  The footing is getting even harder to deal with in this\n"
      +"part of the swamp.\n");
   add_item("path","The beaten path branches southeast and west");
   add_item("fog","The fog is extremely dense");
   add_item("source","The light gleams through the fog from the\nsoutheast direction");
   add_item("light","The light gleams through the fog from the\nsoutheast direction");
   add_item("light source","The light gleams through the fog from the\nsoutheast direction");
   add_exit(ROOMS+"s41","southeast");
   add_exit(ROOMS+"s38","west");
}
