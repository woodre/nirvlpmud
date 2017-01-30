inherit "room/room";

#include "defs.h"

void reset(int arg) {


  if (arg)
    return;

  set_light(1);
  short_desc = GRN+"The Chaos Wood"+NORM;
  long_desc=
    ""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   This wide grassy area slopes down from the west.  The beaten \n"+
    ""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   dirt road travels to the east and to the west here.  A small \n"+
    ""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   village sets nestled within a cove of trees.  The Chaos Wood\n"+
    ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"||"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   looms menacingly to the north.\n"+
    ""+GRN+"#"+NORM+"|"+NORM+BOLD+"X"+NORM+"--"+GRN+"#"+NORM+"   \n"+
    ""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"\n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road2","west",
  "/players/jareel/areas/entrance/road5","east",
  });

}
