inherit "room/room";

#include "defs.h"

void reset(int arg) {


  if (arg)
    return;

  set_light(1);
  short_desc = GRN+"The Chaos Wood"+NORM;
  long_desc=
    ""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   This wide grassy area slopes down from the west.  The ground \n"+
    ""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   seems to be littered with footprints.  An old wooden sign rests\n"+
    ""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   in the center of the beaten path.  The dirt path leads off to \n"+
    ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"||"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   the north and south here, surrounded by fields of green grass \n"+
    ""+GRN+"#"+NORM+"|---"+GRN+"#"+NORM+"   swaying in the breeze.\n"+
    ""+GRN+"#"+NORM+BOLD+"X"+NORM+GRN+"####"+NORM+"\n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road2","north",
  });

}

  init() {
    ::init();
      add_action("Search","search");
      add_action("cmd_south","south");
  }

  status cmd_south(string str) {
    this_player()->move_player("south#room/lanceroad4");
  return 1;
}
