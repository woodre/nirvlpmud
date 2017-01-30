#include "../define.h"
inherit SWAMP

reset(arg) {
   if(arg) return;
   ::reset();
   set_long(
"     Almost like a tunnel through this part of the swamp, the massive\n"+
"grove of the swamplands rises up on both sides of you as you plunge\n"+
"through the thick weeds and foliage of the swamp.  You dig furiously,\n"+
"looking for a way out or a possible exit.\n");
   add_item("grove","The grove of the swamplands emerge from the ground\n"+
      " like a tunnel wall on both sides of you");
   add_item("weeds","The thick, vine-like weeds emerge from the swamp-\n"+
      " waters as though they should really be there");
   add_item("vines","Thick, jungle-like vines that sprout up on several sides of you");
   add_item("foliage","Weeds and vines");
   add_item("vines","Thick, rubbery vines just like in the movies");
   add_exit(ROOM_DIR+"s35","north");
   add_exit(ROOM_DIR+"s13","south"); }

