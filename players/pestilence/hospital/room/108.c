#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <108>"+NORM+"";
long_desc =
  "   This is a normal examining room for the doctor to determin what\n"+
  "illness their patient might have, if any.  There is a shelf with a\n"+
  "small sink to the east.  A garbage can sits next to the shelf, with\n"+
  "the bed being in the middle of the room, covered with white paper.\n"+
  "There are two chairs in the room, and a small round stool used by\n"+
  "the doctor.  On the wall are several health notices and pamphlets.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/whall4.c","out",
});
}
