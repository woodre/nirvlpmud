#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"King Kidema's Hut"+NORM+"";
long_desc =
  "    This is the northern room of the king's hut.   A bed appears near the northern\n"+
  "wall.  The room appears to be quite active, as the pathway on the ground is\n"+
  "is well worn.  It is apparent from the many garbs that the king has somewhat\n"+
  "of a harem.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/kinghut.c","south",
});

}
