#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <304>"+NORM+"";
long_desc =
  "    This is a recovery room for a mother who has recently given birth.\n"+
  "There are two chairs on each side of the room and a bed in the middle.\n"+
  "A television hangs from the wall, to help bring comfort to the new mother.\n"+
  "Several medical machines sit behind the bed.  One to check for a heartbeat,\n"+
  "another to help pump in iv fluids if needed.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/3whall2.c","out",
});
}
