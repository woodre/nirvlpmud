#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital"+NORM+"";
long_desc =
  "    This room is prepared for the birthing of a baby.  In the middle\n"+
  "of the room is a bed with a set of stirups at the end.  There is a chair\n"+
  "on one side of the bed.  On the other side there is some medical equipment.\n"+
  "One is the monitor to listen for the baby's heartbeat, a unit to help provide\n"+
  "iv fluids and pain medicines.  Off against the wall there is a small bed under\n"+
  "a heat lamp for the newborn baby.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/3whall5.c","out",
});
}
