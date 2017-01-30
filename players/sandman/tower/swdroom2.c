#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET fix_sword();

TWO_EXIT("players/sandman/tower/swdroom1", "west",
         "room/church","north",
         "Vault",
         "You are in the Vault of the Sword. Before you on a pillow of\n"+
         "lays the mythical and wonderous Bloodsword. Use it wisely.\n"+
         "Remember, everything requires a price!\n", 1)

fix_sword()  {

object blood_sword;

if (!present("blood sword")) {
   blood_sword = clone_object("players/sandman/WEAPONS/bssword");
   move_object(blood_sword, this_object());
}
return 1;
}
