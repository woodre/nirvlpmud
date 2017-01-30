/*
 * New woods3 room to make use of the daemon objects to get the random long
 * descriptions and monsters
 * -- Rumplemintz
 */

#include "defs.h"

inherit "room/room";

void reset(int arg) {

  if (!present("npc"))
    MOND->populate_monsters(this_object());

  if (arg)
    return;

  set_light(1);
  short_desc = GRN + "The Chaos Wood" + NORM;
  long_desc =
GRN + "###########     " + NORM + "\n" +
GRN + "#" + NORM + "--X--|---" + GRN + "#   " + NORM +
  DESCD->get_long_desc(1) +
GRN + "###" + NORM + HIM + "S" + NORM + GRN + "##" + NORM + "|" + NORM + GRN +
  "####   " + NORM +
  DESCD->get_long_desc(2) +
GRN + "######" + NORM + "|" + NORM + GRN + "####   " + NORM +
  DESCD->get_long_desc(3) +
GRN + "######" + NORM + "|" + NORM + GRN + "####   " + NORM +
  DESCD->get_long_desc(4) +
GRN + "######" + NORM + "|" + NORM + GRN + "####" + NORM + "\n" +
GRN + "######" + NORM + "|" + NORM + GRN + "####" + NORM + "\n";
  items = ({ ITEMS });

  dest_dir = ({
    "/players/jareel/areas/chaos/woods3/wood8", "west",
    "/players/jareel/areas/chaos/woods3/wood10", "east",
    "/players/jareel/areas/chaos/woods3/spire", "south",
  });
}

