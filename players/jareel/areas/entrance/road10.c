inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if (arg)
    return;

  set_light(1);
short_desc=("Town road");
long_desc=
""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   The heavily traveled dirt road comes to an end.  The thick \n"+
""+GRN+"##"+NORM+YEL+"W"+NORM+BOLD+"X"+NORM+BLU+"T"+GRN+"#"+NORM+"   canopy of trees parts here, revealing a crystal blue sky.\n"+
""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   To the west lies '"+BOLD+YEL+"Ye Ole Smithy"+NORM+"' weapons shop.  To the east \n"+
""+GRN+"#"+NORM+"|"+NORM+GRN+"#"+NORM+"||"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   stands a humble '"+BLU+"Orlanthi"+NORM+"' temple.  The road to the south \n"+
""+GRN+"#"+NORM+"|---"+GRN+"#"+NORM+"   travels through town.\n"+
""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"   \n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road9","south",
  "/players/jareel/areas/orlanthi_temple/foyer","east",
  "/players/jareel/areas/entrance/weapons_shop","west",
  "/players/jareel/areas/entrance/smith","north",
  });

}

