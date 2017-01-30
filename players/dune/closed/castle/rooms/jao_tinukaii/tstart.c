inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(0);
    short_desc="Waiting room";
    long_desc=
"     You see to be in the ruins of a temple.  Around you, ruins of other\n"+
"smaller buildings lie scattered about.  The air is moist and humid here.\n"+
"This entrance room looks like it has been abandoned for ages.  Moss and\n"+
"tree roots grow all over the walls and floor.  There is no light source in the\n"+
"room.  Bits and pieces of rubble lie around you.  The room is fairly large.\n"+
"Old worn away paintings line the walls, those that are still intact that is.\n"+
"The room is devoid of furniture.\n";

    dest_dir=({
CASTLEROOM+"/foyer.c","north"  ,
    });

    items=({
"paintings","     You can only make out one painting of the six around the room.\n"+
            "The painting shows a Sithi clutching a strange symbol.  You cannot\n"+
            "make out what the symbol is, but it must be some sort of medallion or\n"+
            "holy symbol",
"rubble",   "     The rubble is simply tiny pieces of stone",
    });
  }
}
