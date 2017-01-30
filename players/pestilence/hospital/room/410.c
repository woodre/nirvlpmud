#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <410>"+NORM+"";
long_desc =
  "    A very large meeting room, where the committed meet daily \n"+
  "for group therapy.  There is a large circle of chairs, a small\n"+
  "television in the corner.  A few couches are also positioned in\n"+
  "a fashion to make viewing the television easy.  There is also\n"+
  "a ping pong table, and a foosball table.  The floor is white tiled\n"+
  "and doesn't appear to have been cleaned in the recent past.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/4whall5.c","out",
});
}
