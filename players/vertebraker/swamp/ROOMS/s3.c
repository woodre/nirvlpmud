#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
      "     Marshland extends in all directions as far as the eye can see.\n"
      +"You wonder at the sheer size of the swamplands, and how you can find\n"+
      "your way home.  The fire from the entrance burns on in the distance,\n"+
      "and the area's climate is cold and harsh.\n");
   add_item("fire","You can see the fire blazing in the distance");
   add_item("marshland","Swampy bogs and swirling marshland");
   add_item("bogs","Twisted bogs of the swamp");
   add_exit(ROOMS+"s12","east");
   add_exit(ROOMS+"s5","north");
   add_exit(ROOMS+"s11","south");
   add_exit(ROOMS+"s1","west");
}
