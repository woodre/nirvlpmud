/*
 * elizas_office.c  without Eliza code -- Rumplemintz
 */
#include "std.h"

object eliza;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_reset(arg) {
  if (!eliza || !living(eliza))
  {
    eliza = clone_object("/players/padrone/inside/npc/eliza");
    move_object(eliza, this_object());
  }
}

extra_init() {
  add_action("do_exit", "exit");
  add_action("do_exit", "out");
}

do_exit() {
  this_player()->move_player("out#players/padrone/inside/courtyard");
  return 1;
}

ONE_EXIT("players/padrone/inside/courtyard","southeast",
     "Eliza's office",
     "This is Eliza's office. Eliza is a psychiatrist,\n"+
     "and usually she meets her clients here.\n"+
     "But some days she takes the afternoon off and\n"+
     "just walks around talking to people.\n", 1)
