#include "std.h"

object butterfly;

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset();

#undef EXTRA_INIT
#define EXTRA_INIT  extra_init();

extra_reset() {
    if (!butterfly) {
#if 0  /* Changing to different way -- Rumplemintz */
	butterfly = clone_object("obj/monster_lars");
	butterfly->set_name("butterfly");
	butterfly->set_level(1);
#if 0 /* adjusting to Nirvana monster.guide - Rumplemintz */
	butterfly->set_ep(60);
	butterfly->set_hp(1);
	butterfly->set_wc(1);
	butterfly->set_ac(10);
#else
        butterfly->set_hp(15);
        butterfly->set_wc(5);
        butterfly->set_ac(3);
#endif
	butterfly->set_al(20);
	butterfly->set_short("A butterfly");
	butterfly->set_long("A beautiful, golden butterfly, happily\n" +
			    "fluttering around among the bushes.\n");
	move_object(butterfly, this_object());
#else
      move_object(clone_object("/players/padrone/outside/npc/np_butterfly"),
                  this_object());
#endif
    }
} /* extra_reset */

extra_init() {
    add_action("kill", "kill");
    add_action("kill", "missile");
    add_action("kill", "shock");
    add_action("kill", "fireball");
    add_action("kill", "kick");
}  /* extra_init */

/* Adding this to stop fighting in this room instead of previous init() */
query_no_fight() { return 1; }
kill(str) {
    if (!str)
	return 0;
    write("No, this place is much too nice for that.\n");
    return 1;
}

TWO_EXIT("players/padrone/outside/small_lake", "north",
	 "players/padrone/outside/nw", "east",
	 "Nice place",
	 "This is really a nice place!\n" +
	 "You are in a small clearing with soft grass\n" +
	 "just at the shore of a small, beautiful lake.\n" +
	 "Tall trees surround the clearing, and to the east\n" +
	 "a small path leads to Padrone's Castle.\n" +
	 "You feel at peace here.\n", 1)

