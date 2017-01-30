#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
      "    Dark, twisted cypress trees prevent you from traveling north, and the\n"
      +"path twists around the assorted bogs and marshes to the west\n"
      +"and south.  You can see the flicker of a campfire back to the south.\n"
      +"Flies and other vermin buzz around your face, which is now drenched\n"
      +"with perspiration.\n");
   add_item("trees","The mangled cypress trees block you from going north\nand proceeding out of the swamp");
   add_item("path","The beaten path wraps around west and south");
   add_item("flicker","You spot smoke rising from the south");
   add_item("smoke","A wisp of smoke coming from the south");
   add_item("flies","Disgusting black flies that land and disappear when you swat at them");
   add_item("vermin","Gnats, flies, and other unsightly pests");
   add_smell("main","You smell your body odor.. *ick*");
   add_exit(ROOMS+"s27","west");
   add_exit(ROOMS+"s10","south");
}
