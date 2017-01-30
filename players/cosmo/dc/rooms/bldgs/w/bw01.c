#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("building");
  short_desc = BLU+"The Washington Monument"+NORM;
  long_desc = 
"A big pencil! \n"+
"Long lines \n"+
"Lots of tourists \n"+
"A large steel door leading the way inside.\n\n";

  items = ({
"door", "The door is chained shut, but you see a sign on it",
"sign", "The Monument should be open soon.\n"
       +"Please be patient",
  });

  dest_dir = ({
    DCSTR+"s003", "east",
  });

}

init() {
  ::init();
}
