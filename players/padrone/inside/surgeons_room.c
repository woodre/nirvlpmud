/*
 * surgeons_room.c
 * stripped out the surgeon -- Rumplemintz
 */

#include "std.h"
#include "../config.h"

object surgeon;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
    add_action("do_exit", "exit");
    add_action("do_exit", "out");
} /* extra_init */

do_exit() {
  this_player()->move_player("out#players/padrone/inside/courtyard");
  return 1;
}

extra_reset(arg) {
  if (!surgeon) {
    surgeon = clone_object("/players/padrone/inside/npc/surgeon");
    move_object(surgeon, this_object());
  }
}

ONE_EXIT("/players/padrone/inside/courtyard", "northeast",
     "The surgeon's operating room",
     "You are in the surgeon's operating room.\n" +
     "If he is here, he can help you to change your description or your sex.\n", 1)
