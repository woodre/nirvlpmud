#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_short("A dark catacomb");
   set_long(
      "     A veiled mist pours into the room from the shaft above your\n"+
      "head.  A thin rope ladder leads up to the Shi'ah SwampLands, and the\n"+
      "catacomb also plunges to the north.  Water trickles down from thin\n"+
      "cracks in the walls, giving the room a cool atmosphere.\n");
   add_item(({"mist","veiled mist"}),
      "A thinly veiled mist that floats down from the swamp");
   add_item("ladder",
      "A creaky rope ladder leads up to the swamp");
   add_item("water",
      "Small trickles of water slime their way down the rock walls");
   add_item("walls",
      "The thick granite walls surround you on three sides");
   add_exit(ROOMS+"s1","up");
   add_exit(VILLAGE+"tun1","north"); }
