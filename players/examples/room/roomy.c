/*
 * roomy.c
 * Rumplemintz@Nirvana
 */

#pragma strong_types

#include "../inc/examples.h"

inherit EXAMPLES_ROOM;

void
configure() {
  EXAMPLES_ROOM::configure();
  set_property(P_OUTSIDE);
  set_property(P_DAYLIGHT);
  set_short("featureless room", "in");
  set_long("This is a featureless room.  It waits to be soon filled with "
           "interesting mudlib features.\n");
  set_exits(({ "./parsy", "./faky" }),({ "east", "south" }));
  set_populate_object(EXAMPLES_OBJ"disguise");
}
