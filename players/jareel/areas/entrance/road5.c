inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if(!present("guard"))  {
    MOCO("/players/jareel/monsters/town/yelmalian_infantry.c"),this_object()); } 

  if (arg)
    return;

  set_light(1);
  short_desc = GRN+"The Chaos Wood"+NORM;
  long_desc=
    ""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   This wide grassy area slopes down from the west.  The ground \n"+
    ""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   is littered with thousands of footprints, heading off to the \n"+
    ""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   east.  To the north rest a rather small, unimpressive village.\n"+
    ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"||"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   The worn dirt road travels to the east, west and branches\n"+
    ""+GRN+"#"+NORM+"|-"+NORM+BOLD+"X"+NORM+"-"+GRN+"#"+NORM+"   north into the village.\n"+
    ""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"   \n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road4","west",
  "/players/jareel/areas/entrance/road6","east",
  "/players/jareel/areas/entrance/road8","north",
  });

}
