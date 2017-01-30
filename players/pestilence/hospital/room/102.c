#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <surgery 102>"+NORM+"";
long_desc =
  "    This is one of three surgery rooms.  The room is in a sterile\n"+
  "condition.  There is several lights hanging down to help view the\n"+
  "procedure.  To the east there is a few shelves with operating tools\n"+
  "on it.  The surgery table sits in the middle of the room and it appears\n"+
  "there is a surgery that is in progress.\n";
set_light(3);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({

  "/players/pestilence/hospital/room/whall.c","out",
});
}
