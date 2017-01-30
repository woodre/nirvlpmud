inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if(!present("elite")) {
    MOCO("/players/jareel/monsters/town/yelmalian_elite_guard.c"),this_object()); }
  if(!present("elite 2") && present("elite"))  {
    MOCO("/players/jareel/monsters/town/yelmalian_elite_guard2.c"),this_object()); }

  if (arg)
    return;

  set_light(1);
  short_desc = GRN+"The Chaos Wood"+NORM;
  long_desc=
    ""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   The grassy area boarders a densely packed group of trees here.\n"+
    ""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   To the west rest a huge fortification bearing the markings of \n"+
    ""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   the Yelmalian order.  The once-proud walls of the fortress have \n"+
    ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"|"+BOLD+"X"+YEL+"Y"+NORM+GRN+""+NORM+"   become overgrown with weeds and are slowly falling into a rubble \n"+
    ""+GRN+"#"+NORM+"|---"+GRN+"#"+NORM+"   of disrepair.  The tall gates are closed and there isn't an \n"+
    ""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"   obvious way in.  There worn dirt path leads south.\n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road6","south",
  "/players/jareel/areas/entrance/road7","north",
  "/players/jareel/areas/town1/fort/road4","east",
  });

}
