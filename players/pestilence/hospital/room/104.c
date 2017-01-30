#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <104>"+NORM+"";
long_desc =
  "    This is the room where they cast all kinds of broken bones.\n"+
  "There is an adjustable bed in the middle of the room.  Some\n"+
  "medical instruments on the shelves to the east and west.  The\n"+
  "walls are covered with all sizes of casts and for different limbs.\n"+
  "A couple wheelchairs are in the corner, along with some crutches\n"+
  "ror those with broken legs and feet.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/whall2.c","out",
});
}
