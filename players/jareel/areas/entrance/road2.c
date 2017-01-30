inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if(!present("hermit"))  {
    MOCO("/players/jareel/monsters/town/hermit.c"),this_object()); }

  if (arg)
    return;

  set_light(1);
  short_desc = GRN+"The Chaos Wood"+NORM;
  long_desc=
    ""+GRN+"###"+YEL+"S"+GRN+"##"+NORM+"   This wide grassy area slopes down from the east.  The worn \n"+
    ""+GRN+"##"+NORM+YEL+"W"+NORM+"|"+BLU+"T"+GRN+"#"+NORM+"   dirt path been pounded over and over by what must be a ton of\n"+
    ""+GRN+"#"+BOLD+"F"+NORM+YEL+"H"+NORM+"|"+RED+"B"+GRN+"#"+NORM+"   militia on foot.  An animal skull rests by the side of the \n"+
    ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"||"+BOLD+YEL+"Y"+NORM+GRN+""+NORM+"   road encased in several rocks .  The road travels to the \n"+
    ""+GRN+"#"+NORM+BOLD+"X"+NORM+"---"+GRN+"#"+NORM+"   north, south and east from here.\n"+
    ""+GRN+"#"+NORM+"|"+NORM+GRN+"####"+NORM+"\n";

  items = ({ ITEMS });

  dest_dir = ({
    "/players/jareel/areas/entrance/road1","south",
    "/players/jareel/areas/entrance/road3","north",
    "/players/jareel/areas/entrance/road4","east",
  });

}