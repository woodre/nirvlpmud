#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/realms/keats/room.c";

string Location;

reset(arg) {
  if(arg) return;
  short_desc = KEATS;
  Location = "Il Re triste Quadrato Bila";
  long_desc = 
    "\n                   "+HIW+"Saint Antonius' Way"+HIC+" (["+NORM+"northeast"+HIC+"])"+NORM+"\n"+
    "                   "+HIW+"The Viggius Road"+HIC+" (["+NORM+"southeast"+HIC+"])"+NORM+"\n"+
    "                   "+HIW+"Avenue of the Word"+HIC+" (["+NORM+"north"+HIC+"])"+NORM+"\n"+
    "                   "+HIW+"Il sentiero dei Morti"+HIC+" (["+NORM+"southwest"+HIC+"])"+NORM+"\n"+
    "                   "+HIW+"Market Street"+HIC+" (["+NORM+"northwest"+HIC+"])"+NORM+"\n"+
    "  The great Square of Sad King Billy opens up before you.  Stretching\n"+
    "hundreds of men across, the hexagonal square marks the location of the\n"+
    "founding of the City of Keats by the monarch himself.  Towering gates\n"+
    "mark the commencement of each of the five major roads inside the city,\n"+
    "while a cobbled pathway circles the expanse of grass that makes up the\n"+
    "bulk of the plaza.  Standing tall in the center of the square is the\n"+
    "legendary Tower of the Magi, home to the Mages.\n";
  add_item("item",
    "add items here");
  add_exit(RMS+"1antonius01.c", "northeast");
  add_exit(RMS+"1viggus01.c", "southeast");
  add_exit(RMS+"1word01.c", "south");
  add_exit(RMS+"1morti01.c", "southwest");
  add_exit(RMS+"1market01.c", "northwest");
  set_light(1);
}
