/*
 * workroom.c
 *
 * My workroom on LD - Rumplemintz
 */
#pragma strong_types

inherit "complex/room";

void configure() {
  ::configure();
  set_property(P_INSIDE);
  set_property(P_DAYLIGHT);
  set_short("Rumplemintz's workroom", "in");
  set_long("This is Rumplemintz's workroom. It waits to be configured with "
           "spiffy descriptions, items, exits, and meaningless actions for "
           "people to play with.\n");
  set_exits(({
    "/room/church", "/room/adv_guild", "/room/shop"
    }),({
    "church", "guild", "shop"
  }));
  set_populate_object("/players/examples/obj/disguise");
}

