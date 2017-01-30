#include "std.h"

  object button;
   object poster;
   object chair;
   int xx;
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
      if (!button || !present(button)) {
   button = clone_object("players/boltar/things/button.c");
   move_object(button, this_object());
}
      if (!chair || !present(chair)) {
   chair = clone_object("players/boltar/things/chair.c");
   move_object(chair, this_object());
}
/*
     if (!poster || !present(poster)) {
   xx = random(10);
   if (xx < 5) {
   poster = clone_object("players/boltar/pic/poster.c");
   }
   if (xx >4) {
   poster = clone_object("players/boltar/pic/poster2.c");
   }
   move_object(poster, this_object());
  }
*/
}
ONE_EXIT("players/boltar/lv1/plastiroom.c", "east",
  "The dougnut room",
 "In this room you see two tables and a few chairs scattered about.\n" +
 "On the tables and on floor there are many empty doughnut boxes, as well as\n" +
 "many old empty paper cups and all around the crumbs left behind from the   \n" +
 "doughnuts that had been eaten here.\n", 1)
