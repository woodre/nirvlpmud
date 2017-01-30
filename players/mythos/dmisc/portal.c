#include "/players/mythos/closed/ansi.h"
id(str) { return str == "portal"; }

short() { return CYN+"Portal"+NORM; }

long() { write("A shimmering portal that hangs in the air before you.\n"+
               "'enter portal' will lead to the Chamber of Realms\n");
       }
       
get() { return 0; }
drop() { return 0; }
query_value() { return 0; }

init() {
  add_action("enter","enter");
}

enter(str) {
  if(!str) return 0;
  if(str == "portal") {
    write("You touch the portal\n");
    this_player()->move_player("portal#players/mythos/enterance.c");
  return 1; }
}