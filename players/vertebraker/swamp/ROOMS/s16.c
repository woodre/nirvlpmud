#include "../define.h"
inherit SWAMP

reset(arg) {
   if(arg) return;
   ::reset();
   set_long(
"     The footing in this part of the swamp is terrible, the feeling\n"+
"of isolation is also overwhelming.  Strangely, on a nearby tree there\n"+
"are bloodstains, you wonder if they are just animal.. or if they are\n"+
"human.  A passing gator seems to dispute your gut instinct.\n");
   add_item("tree","On this short cypress tree, there is a curious\n"+
      " amount of blood");
   add_item(({"bloodstains","blood","stains"}),
      "The stains on the tree have left a dark brown discoloration\n"+
      " to the green tree");
   add_item("gator","The gator submerges beneath the water as you\n"+
      " try to get a closer peek");
   add_touch("bloodstains","You touch the bloodstains and no blood will come\n"+
      " off - it is dry and crusted");
   add_touch("blood","You touch the bloodstains and no blood will come\n"+
      " off - it is dry and crusted");
   add_exit(ROOM_DIR+"s5","southwest");
   add_exit(ROOM_DIR+"s18","north");
   add_exit(ROOM_DIR+"s13","east"); }
