inherit "room/room";

#include "defs.h"

void reset(int arg) {


  if (arg)
    return;

  set_light(1);
  short_desc = GRN+"The Chaos Wood"+NORM;
  long_desc=
""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   This wide grassy area slopes down from the west.  The path \n"+
""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   to the north slopes down to a two large gates, what appears \n"+
""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   to be the front door of a huge fortification.  The road to \n"+
""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"||"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   the west leads back to the town of Hendriksville.\n"+
""+GRN+"#"+NORM+"|--"+NORM+BOLD+"X"+NORM+GRN+"#"+NORM+"   \n"+
""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"\n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road5","west",
  "/players/jareel/areas/entrance/road7","north",
  });

}