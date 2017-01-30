#include <prop/room.h>
#include <exits.h>

inherit "complex/room";

void configure() {
  room::configure();
  set_short("a sandy beach", "on");
  set_long("\
A small sandy beach. Some stairs to the south lead to the main road. \
The sound of the waves, surfing onto the beach, fills the air. \
To the north the beach continues.\n");
  set_exits(
    ({ "room/vill_shore2",
       "room/vill_shore2",
       "room/beach2" }),
    ({ "south",
       "up",
       "north" }),
    0,
    ({ 0,
       EXIT_INVISIBLE,
       0 })
  );
  set_property(P_PLAIN_ROOM);
  set_property(P_OUTSIDE);
  set_property(P_WATER);
  set_property(P_DAYLIGHT);
}

