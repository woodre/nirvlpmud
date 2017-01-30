#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

int i;

reset(arg) {
  if(arg) return;
  set_room_type("building");
  short_desc = BLU+"Lincoln Memorial"+NORM;
  long_desc = 
"You step inside the Memorial and gape in awe at the 19 foot\n"+
"statue of the 16th president, Abraham Lincoln.  You are amazed\n"+
"to see that a man who did so much for his country could look so\n"+
"peaceful seated in his throne, looking out eastward over the \n"+
BLU+"Reflecting Pool"+NORM+" and the "+BLU+"Washington Monument"+NORM+".\n\n";

  items = ({
"memorial", "Writing covers the walls.  Perhaps you could read it",
"statue", "One hand has a closed fist, while the other takes the shape of an L",
"lincoln", "One hand has a closed fist, while the other takes the shape of an L",
"throne", "You see nothing special",
  });

  dest_dir = ({
    DCSTR+"s107", "north",
    DCSTR+"s207", "south",
    DCBLDG+"r/br01", "east",
    DCSTR+"s501", "west",
  });

  if(!present("tourist", TO)) {
    for(i=0;i<2;i++) { MO(CO(DCMON+"tourist.c"), TO); }  
  }
  if(!present("tourguide", TO)) {
    MO(CO(DCMON+"tourguide.c"), TO);
  }
}

init() {
  ::init();
}
