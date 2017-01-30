inherit "room/room";

#include "defs.h"

void reset(int arg) {


  if (arg)
    return;

  set_light(1);
  short_desc = GRN+"The Chaos Wood"+NORM;
  long_desc=
    ""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   This wide grassy area slopes down from the west.  The Chaos \n"+
    ""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   Wood looms menacingly to the north.  The woods thick canopy\n"+
    ""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   of trees create deep dark shadows, that seem to mimic every \n"+
    ""+GRN+"#"+NORM+BOLD+"X"+NORM+GRN+"#"+NORM+"||"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   movement.  The path to the south leads back to civilization.\n"+
    ""+GRN+"#"+NORM+"|---"+GRN+"#"+NORM+"   \n"+
    ""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"\n";

  items = ({ ITEMS });

  dest_dir = ({
    "/players/jareel/areas/entrance/road2","south",
    "/players/jareel/areas/chaos/forest1","north",
  });

}