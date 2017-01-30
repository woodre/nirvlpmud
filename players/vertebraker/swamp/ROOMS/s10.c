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
   add_item("fog","Thick and deep, the fog begins to tear\ninto your every pore");
   add_item("roads","Not really roads, but cleared paths");
   add_exit(ROOM_DIR+"s28","north");
   add_exit(ROOM_DIR+"s19","south");
   add_exit(ROOM_DIR+"s7","southwest");
   add_exit(ROOM_DIR+"s18","southeast");
}
