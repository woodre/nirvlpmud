#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <106>"+NORM+"";
long_desc =
  "    This is the mri room.  There is a very large mri unit in the \n"+
  "middle of the room.  It appears large enough to scan the whole body.\n"+
  "To the east there is a desk with a computer, which appears to control\n"+
  "the mri machine.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/whall3.c","out",
});
}
