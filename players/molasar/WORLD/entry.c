
#include "std.h"

reset(arg) {
   if(arg) return;
   set_light(1);
}

id(str) { return str == "mist" || str == "swirling mist"; }

init() {
     add_action("enter","enter");
     add_action("enter","west");
}

enter() {
     this_player()->move_player("enters the mist#players/molasar/WORLD/room1");
     return 1;
}

short() { return "An entrance to a different world"; }

long(str) {
    if(str == "mist" || str == "swirling mist") {
      write("A softly glowing mist.\n");
      write("You feel a strong urge to enter it.\n");
      return 1;
    }
    write("You are caught in a rift between time and space.\n");
    write("There is darkness all about you.  The only source of light\n");
    write("is a swirling mist to your west.\n");
}

