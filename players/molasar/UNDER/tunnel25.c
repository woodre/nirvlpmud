
#include "std.h"

reset(arg) {
     if(!arg)
       set_light(0);
}

id(str) { return str == "door"; }

init() {
     add_action("push","push");
     add_action("southwest","southwest");
}

southwest() {
     call_other(this_player(),"move_player",
                    "southwest#players/molasar/UNDER/tunnel24");
     return 1;
}

push(str) {
     if(!str) {
       write("Push what?\n");
       return 1;
     }
     if(str == "door") {
       write("The door gives away easier than expected!\n");
       write("You fall headlong into the next room.\n");
       call_other(this_player(), "move_player",
                      "through door#players/molasar/UNDER/tunnel20");
       return 1;
     }
}

short() { return "A secret passage"; }

long(str) {
     if(str == "door") {
       write("An unusual looking door made out of the cavern walls with\n");
       write("the hinges set so it only opens outward.  \n");
       return 1;
     }
     write("The passage widens a bit here allowing some greater movement.\n");
     write("At first glance this appears to be a dead end, but looking at\n");
     write("the south wall you notice a strange looking door.  It seems\n");
     write("to be constructed so that it can only be opened from one side.\n");
     write("If you push hard enough you might be able to open it.\n");
     write("   There is one obvious exit:  southwest\n");
}

