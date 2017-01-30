#include "../define.h"
inherit SWAMP
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     The immediate area seems to be some sort of crossroads in the\n"+
"swamp, where one can take one of the divergent roads that lead\n"+
"through the swamp.  The fog is so thick however, that your line of\n"+
"sight does not extend much beyond this.\n");
   add_item("fog","You curse the dreaded fog!");
   add_item("roads","Not really roads, but cleared paths");
   add_exit(ROOMS+"s16","west");
   add_exit(ROOMS+"s14","north");
   add_exit(ROOMS+"s15","east");
   add_exit(ROOMS+"s12","southwest");
}
