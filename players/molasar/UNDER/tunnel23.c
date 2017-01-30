
#include "std.h"

reset(arg) {
     if(!arg) 
       set_light(0);
      extra_reset();
}

object crown;

extra_reset() {
      if(!present("crown")) {
        crown = clone_object("players/molasar/TREASURE/elven_crown");
        move_object(crown, this_object());
      }
}

init() {
     if(!present("qstob2", this_player())) {
       write("You did not go by the right paths!\n");
       move_object(this_player(), "/room/church");
       return 1;
     }
     add_action("northwest","northwest");
}

northwest() {
     call_other(this_player(),"move_player",
                    "northwest#players/molasar/UNDER/tunnel24");
     return 1;
}

short() { return "A secret room"; }

long() {
     write("This is a secret room known only to the orcs of the mountain,\n");
     write("however the means on how to get here was long lost to them.\n");
     write("The room's main purpose was to hide valuable items taken on\n");
     write("their many raids and plunderings.\n");
     write("   There is on obvious exit:  northwest\n");
}

