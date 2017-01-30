#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <201>"+NORM+"";
long_desc =
  "   A very small hospital room.  There are two beds in this\n"+
  "room, with a curtain that divides the room into two parts.\n"+
  "You can see that the way back to the hallway is to the north.\n";
set_light(1);

items = ({
  "bed","A single size bed, which can be adjusted up and down.",
  "curtain","A flimsy curtain which can be pulled closed or open to divide the room.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/2whall.c","out",
});
}
