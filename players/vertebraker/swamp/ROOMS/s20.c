#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     The immediate area seems to be some sort of crossroads in\n"+
"the swamp, where one can take one of the divergent roads that lead\n"+
"through the swamp.  The fog is so thick however, that your line\n"
+"of sight does not extend much beyond this.\n");
   add_item("fog","Thick and deep, the fog begins to tear\ninto your every pore");
   add_item("roads","Not really roads, but cleared paths");
   add_exit(ROOMS+"s21","west");
   add_exit(ROOMS+"s22","north");
   add_exit(ROOMS+"s4","east");
   add_exit(ROOMS+"s9","south");
}
