inherit "room/room";

#include "defs.h"

void reset(int arg) {


  if (arg)
    return;

  set_light(1);
short_desc=(BOLD+GRN+"Hendrikville"+NORM);
long_desc=
""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   The worn dirt road twists and turns within the canopy of trees.\n"+
""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   The dirt path leads into the small town of Hendricksville.  The \n"+
""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   worn down buildings to the north look as if they have endured \n"+
""+GRN+"#"+NORM+"|"+NORM+GRN+"#"+NORM+BOLD+"X"+NORM+"|"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   several raiding parties.  A fountain rests along the path to the \n"+
""+GRN+"#"+NORM+"|---"+GRN+"#"+NORM+"   north, while south leads out of town.\n"+
""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"   \n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road9","north",
  "/players/jareel/areas/entrance/road5","south",
  });

}

