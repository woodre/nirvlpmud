#include "std.h"
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
ONE_EXIT("players/mistress/sci_fi/shark.c","back",
   "Entrance to sharks",
   "\n" +
   "You find yourself standing a pool of water and waist high.  Dorsal fins\n" +
   "circle you - it is difficult to count them all.  The legendary jaws may\n" +
   "be in the vicinity,  but you might have to fight his relatives first.\n",1)
 
extra_init() {
     add_action("shark","north");
     add_action("shark","south");
     add_action("shark","east");
     add_action("shark","west");
     }
 
shark() {
    call_other(this_player(),"move_player"," to find sharks#players/mistress/sci_fi/shark/baby.c");
    return 1; }
