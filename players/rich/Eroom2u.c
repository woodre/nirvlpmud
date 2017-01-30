#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

TWO_EXIT("players/rich/hall5u.c", "east",
   "players/rich/turbo2u.c", "west",
   "room",
	"This is a corridor with a strange\n"+
	"tube in the wall that you could\n"+
	"probably enter.\n",
           1)
realm(){return "enterprise";}

extra_init() {
  add_action("enter","enter");
}

enter(str) {
if(!str) { write("Enter what?\n"); return 1; }
if(str == "tube") {
  this_player()->move_player("tube#players/rich/quest/main1.c");
  return 1; }
}
