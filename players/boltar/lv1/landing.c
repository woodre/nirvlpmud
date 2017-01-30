#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
     add_action("look", "look");
     add_action("look", "l");
     add_action("sit", "sit");
     add_action("look", "examine");
     add_action("look", "search");
  }
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "at chairs" || str == "at chair") {
   write ("The chairs look like they would be nice to sit in.\n");
   return 1;
  }
return 0;
}
sit() {
   write("You sit down on a chair and relax.\n");
   say(call_other(this_player(), "query_name", 0) + " sits on one of the chairs.\n");
  return 1;
 }
ONE_EXIT("players/boltar/lv1/plastiroom.c", "east",
   "The landing pad.",
   "This is the area where one ends up after bouncing off the workroom\n" +
   "shields, If Boltar wishes to speak with you, he will be here shortly.\n" +
   "The room has some chairs for you to sit on.\n", 1)
