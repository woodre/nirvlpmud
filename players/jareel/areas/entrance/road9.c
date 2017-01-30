inherit "room/room";

#include "defs.h"

void reset(int arg) {

   if(!present("fountain"))  {
     MOCO("/players/jareel/general_stuff/fountain.c"),this_object()); }
  if (arg)
    return;

  set_light(1);
  short_desc=("Town square");
  long_desc=
    ""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   The worn dirt road twists and turns within the small town,\n"+
    ""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   circling a small spurting fountain.  To the east you see \n"+
    ""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+BOLD+"X"+NORM+RED+"B"+GRN+"#"+NORM+"   the legendary bar '"+RED+"The Bloody Axe"+NORM+"'.  To the west sits a \n"+
    ""+GRN+"#"+NORM+"|"+NORM+GRN+"#"+NORM+"||"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   small shop called '"+BOLD+YEL+"The Healing Salve"+NORM+"'. The road twists to \n"+
    ""+GRN+"#"+NORM+"|---"+GRN+"#"+NORM+"   the north through town, and travels south out of town.\n"+
    ""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"\n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road10","north",
  "/players/jareel/areas/entrance/road8","south",
  "/players/jareel/areas/entrance/bloody_axe","east",
  "/players/jareel/areas/entrance/heal_shop","west",
  });

}

