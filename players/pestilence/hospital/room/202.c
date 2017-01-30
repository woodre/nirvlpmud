#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <202>"+NORM+"";
long_desc =
  "   A very small hospital room.  There are two beds in this\n"+
  "room, with a curtain that divides the room into two parts.\n"+
  "You can see that the way back to the hallway is to the north.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/2whall.c","out",
});
}
