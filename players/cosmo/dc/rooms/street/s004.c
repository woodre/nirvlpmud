#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("street");
  short_desc = GRN+"14th and Constitution"+NORM;
  long_desc = 
"At the intersection of "+GRN+"14th Street and Constitution Avenue"+NORM+
"\nyou begin to realize how big this city really is.  In every\n"+
"direction you see large buildings.  The green grass of the Mall\n"+
"is to the south, and many other adventures can be seen all around\n"+
"you.  Running "+
"east/west here is "+GRN+"Constitution Ave"+NORM+".  Many museums of\n"+
"the Smithsonian can be found to the east, and the "+BLU+"Washington\n"+
"Monument"+NORM+" remains in your sights to the southwest.\n\n";

  items = ({
  });

  dest_dir = ({
    DCSTR+"s003a", "south",
    DCSTR+"s213", "east",
    DCSTR+"s215", "west",
  });
}

init() {
  ::init();
}
