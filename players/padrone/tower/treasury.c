#include "std.h"
#include "/obj/door.h"

object obj_1, obj_2;	/* Used by the MAKE_DOORS macro */

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {

    if (!arg) {
	/* First reset */

#if 0 /* Rumplemintz - macro doesn't work, changing it */
	MAKE_DOORS("players/padrone/tower/treasury", "north",
		   "players/padrone/tower/vault", "south",
		   "maximum-security", "vaultdoor",
		   "This is a door made of steel and mithril, several inches thick.\n",
		   1, 1, 1)
         return;
#else
    if (!present("door"))
    {
      obj_1 = clone_object("obj/door");
      obj_1->set_dir("north");
      obj_1->set_door_room("/players/padrone/tower/treasury");
      obj_1->set_type("maximum-security");
      obj_1->set_code("vaultdoor");
      obj_1->set_door_long("This is a door made of steel and mithril, several inches thick.\n");
      obj_1->set_locked(1);
      obj_1->set_closed(1);
      obj_1->set_can_lock(1);

      obj_2 = clone_object("obj/door");
      obj_2->set_dir("south");
      obj_2->set_door_room("/players/padrone/tower/vault");
      obj_2->set_type("maximum-security");
      obj_2->set_code("vaultdoor");
      obj_2->set_door_long("This is a door made of steel and mithril, several inches thick.\n");

      obj_1->set_door(obj_2);
      obj_2->set_door(obj_1);
      move_object(obj_1, this_object());
      move_object(obj_2, "/players/padrone/tower/vault");
      obj_1->set_both_status();
    }
#endif
    }

#if 0 /* Don't need this - Rumplemintz */
    obj_1->set_closed(1);
    obj_1->set_locked(1);
    obj_1->set_both_status();
#endif
} /* extra_reset */


TWO_EXIT("players/padrone/tower/rambo_room", "south",
	 "players/padrone/tower/vault", "north",
	 "Treasury",
	 "You are standing just outside the great door\n" +
	 "leading to the vault where the treasure is stored.\n" +
	 "You notice that the floor has been engraved with anti-teleport runes.\n", 1)

/* This room is teleport-safe */
realm() { return "NT"; }

