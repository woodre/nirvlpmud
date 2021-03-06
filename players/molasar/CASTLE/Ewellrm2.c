
#include "std.h"

reset(arg) {
     if(!arg)
       set_light(0);
     extra_reset();
}

object mage;

extra_reset() {
  if(!present("mage")) {
    mage = clone_object("players/molasar/MONSTERS/mage");
    move_object(mage,this_object()); }
}

init() {
     add_action("up","up");
}

up() {
     call_other(this_player(),"move_player",
                    "up#players/molasar/CASTLE/wellrm1");
     return 1;
}

short() { return "Bottom of the well"; }

long() {
     write("This is the bottom of a long since dried out well.  Iron \n");
     write("rungs on the side of the well provide a way out.\n");
     write("   There is one obvious exit:  up\n");
}

