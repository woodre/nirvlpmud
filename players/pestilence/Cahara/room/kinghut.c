#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"King Kidema's Hut"+NORM+"";
long_desc =
  "    This is the large hut of King Kidema.  The wall are made of well contoured\n"+
  "mud.  There are rooms connected to the north, south, and east.  The king\n"+
  "is well off.  A large pile of hides lay on the floor.  There is a large\n"+
  "table in the middle of the room.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/nkinghut.c","north",
  "/players/pestilence/Cahara/room/skinghut.c","south",
  "/players/pestilence/Cahara/room/ekinghut.c","east",
  "/players/pestilence/Cahara/room/cvillage.c","west",
});

}
