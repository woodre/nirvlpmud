#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <302>"+NORM+"";
long_desc =
  "    This is a large room for caring of newborns.  There are rows\n"+
  "of basinets filling the room.  There are several empty bottles and\n"+
  "formula cans on the counters.  Crying can be heard as some of the\n"+
  "babies appear to be getting neglected, and left hungry.  In the west\n"+
  "corner there is a garbage can overflowing with soiled diapers.  A few\n"+
  "boxes of diapers sit on the floor.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/3whall.c","out",
});
}
