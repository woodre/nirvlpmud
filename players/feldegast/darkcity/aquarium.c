#include "def.h"

inherit MYROOM;

reset(arg) {
  if (arg) return;
  set_light(0);
  short_desc="Neptune's Kingdom";
  long_desc=
"     Exotic sea creatures, fish, and mollusks dance before your eyes\n\
in their dimly lit fish tanks which are the only source of light in\n\
the room.  A wheelchair accessible ramp leads to the back.\n";
  items=({
    "creatures","Squid, star fishes, sea anemones, and other creatures",
    "fish","Rainbow fish, puffer fish, and electric eels",
    "mollusks","Clams, snails, and muscles",
    "ramp","A ramp leading to the east"
  });
  dest_dir=({
    PATH+"street9","west",
    PATH+"backroom","east"
  });
}   
init() {
  ::init();
  add_action("cmd_smell","smell");
}
cmd_smell() {
  write("Something smells fishy.\n");
  say(this_player()->query_name()+" sniffs.\n");
  return 1;
}

