#include "room.h"
#include "/players/hippo/rvd.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset(){
if(!present("pole")){
  move_object(clone_object("/players/hippo/objects/game_pole"),this_object());
}
}
ONE_EXIT("/players/hippo/rooms/mouth","mouth",
  "The nose, which is obviously not a normal nose.",
  "You arrived in Hippo's nose. If you expected to find things\n"+
  "which normally belong in a nose in here, you were wrong. This\n"+
  "nose looks more like the entrance to a lot of nice things like\n"+
  "a puzzle room, several games like blackjack and oware and to a\n"+
  "room where you can play a nice cardgame.\n"+
  "Look at the pole in the middle of the nose for more information.\n",
         1)
