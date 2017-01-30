#include "/players/cosmo/dc/defs.h"
inherit "players/cosmo/dc/dc_room";

reset(arg) {
  if(arg) return;
  set_room_type("building");
  short_desc = BLU+"Bureau of Printing and Engraving"+NORM;
  long_desc = 
"YES!!  This is what you have always dreamed of.  The place\n"+
"where all the money is made!  Perhaps, if you are lucky, you\n"+
"can find a way inside and just maybe get your hands on some\n"+
"of it.  Nobody would notice if a few coins are missing,\n"+
"right???  You see a large steel door leading the way inside.\n\n";

  items = ({
"door", "The door is chained shut, but you see a sign on it",
"sign", "The Bureau and its treasures should be open soon.\n"
       +"Please be patient",
  });

  dest_dir = ({
    DCSTR+"s001", "east",
  });

}

init() {
  ::init();
}
