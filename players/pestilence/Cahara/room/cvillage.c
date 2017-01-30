#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"Village Center"+NORM+"";
long_desc =
  "    This is the center of the village.  The village seems to be\n"+
  "one of a barbaric tribe.  In the four corners surrounding the\n"+
  "center of the village, stands four long poles.  Atop of these\n"+
  "poles there are skulls from an animal.  It's obvious that this\n"+
  "tribe doesn't like visitors.  In the very center there is a large\n"+
  "throne.  It stands ten feet high.  The village continues to the\n"+
  "north, east, west and goes back to the south.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/nwvillage.c","south",
  "/players/pestilence/Cahara/room/dalekahut.c","west",
  "/players/pestilence/Cahara/room/kinghut.c","east",
});

}
