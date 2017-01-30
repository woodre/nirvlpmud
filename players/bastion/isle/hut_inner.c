
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT \
     add_action("out","out"); \
     add_action("out", "quit");
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object ob, ob2;
     if(!present("demon")) {
          if(!present("man")) {
               ob=clone_object("players/bastion/monster/hermit");
               move_object(ob, this_object());
               return 1; } }
}

ONE_EXIT("players/bastion/isle/hut", "out",
     "Inside Hut",
     "You have entered a small, thatched hut. An old man busily sweeps the\n"+
     "floor, alternately whistling and complaining of a sore back. The\n"+
     "furnishings are simple: a small bed, a table, a chest and a grass rug.\n",
     1)

out() {
   if(this_player()->query_ghost()) return 0;
   if( (this_player()->query_attrib("ste") * 2) < random(100) ) {
     if((present("demon")) || (present("anthrax"))) {
          write("You can't seem to do that now.\n");
          return 1; }
   }
   return 0;
}

realm() { return "NT"; }
