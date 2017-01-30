
#include "../define.h"
inherit SWAMP

reset(arg) {
   if(arg) return;
   ::reset();
   set_long(
      "     Dimly lit as the rest of the swamp, this seemingly neverending\n"+
      "maze of marsh and bog continues to the north, south, and east, while\n"+
      "further confusing your senses with how terribly humid it is here.  You\n"+
      "wipe the sticky sweat from your forehead and continue onward.\n");
   add_item(({"marsh","bog"}),
      "Twisted marsh and bog confront you on every twist\n"+
      " and turn of this massive swampland");
   add_exit(ROOM_DIR+"s23","north");
   add_exit(ROOM_DIR+"s20","south");
   add_exit(ROOM_DIR+"s6","east");
}
