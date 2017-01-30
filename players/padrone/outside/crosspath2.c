#if 0 /* Changed to room/room - Rumplemintz */
#include "std.h"

/* On NannyMud, there is a plague of birds... */
#ifdef NANNY
#undef EXTRA_MOVE2
#define EXTRA_MOVE2 \
    if (this_player()->query_npc() && this_player()->query_name() == "Bird") \
    	return 0;
#endif

TWO_EXIT("players/padrone/outside/crossing", "west",
	 "players/padrone/outside/finish_quest", "east",
	 "A small path",
	 "You are on a small path winding through the bushes.\n", 1)

#else
inherit "room/room";

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_light(1);
  short_desc = "A small path";
  long_desc = "You are on a small path winding through the bushes.\n";
  dest_dir = ({
    "players/padrone/outside/crossing", "west",
    "players/padrone/outside/finish_quest", "east"
  });
}
#endif
