#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
      extra_reset();
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
     add_action("enter", "enter");
  }
object mirror,homemirror;
TWO_EXIT("players/boltar/sprooms/mtv.c", "east",
 "players/boltar/lv2/endless3.c", "west",
	   "cartoon hall",
 "As you enter this room you notice everything looks like a cartoon drawing,\n" +
 "including you.  The hallway looks endless.\n", 1)

enter() {
    write("None of the mirrors here work.\n");
    return 1;
}

extra_reset() {
    if (!mirror) {
        mirror = clone_object("players/boltar/things/light");
        call_other(mirror, "roomset", this_object());
        move_object(mirror, "players/boltar/lv2/endless3");
    }
      if (!homemirror) {
          homemirror = clone_object("players/boltar/things/light");
          call_other(homemirror, "roomset", "players/boltar/lv1/dnroom.c");
          move_object(homemirror, "players/boltar/lv2/endless3");
    }
      transfer(mirror, "players/boltar/lv1/dnroom.c");
      transfer(homemirror, "players/boltar/lv2/bluesroom");
}
