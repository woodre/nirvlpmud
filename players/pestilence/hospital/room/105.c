#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <105>"+NORM+"";
long_desc =
  "    This is the x-ray room.  There is a table in the middle of\n"+
  "of the room.  A large x-ray machine hangs from the ceiling.\n"+
  "In the east side of the room is a small booth, where the\n"+
  "radiologist sits while the x-ray is in session.  A large lead\n"+
  "apron hangs from one of the several hooks on the wall.  A chair\n"+
  "is on the west side of the room.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/whall3.c","out",

});
}
