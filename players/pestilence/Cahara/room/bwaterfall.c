#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"Behind a "+CYN+"Waterfall"+NORM+"";
long_desc =
  "    "+CYN+"Water falls"+NORM+" to the ground to the north.  This area is directly behind a large\n"+
  "waterfall.  A solid rock all stands to the east.  A small path leads away from the.\n"+
  "waterfalls to the west.  A hole in the rock still exists to the south.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/cave2.c","south",
  "/players/pestilence/Cahara/room/waterfall.c","north",
});

}
