#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"King Kidema's Hut"+NORM+"";
long_desc =
  "    A large fire pit sits in the middle of the room, which appears to be somewhat\n"+
  "of a kitchen.  There are a few bones scattered about, as if they have been cleaned\n"+
  "off, with no sign of tissue left on the bone.  A large rack is near the east wall.   The\n"+
  "ground appears to be well worn here, making it seem that many a feasts have been\n"+
  "prepared at this fire\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/kinghut.c","west",
});

}
