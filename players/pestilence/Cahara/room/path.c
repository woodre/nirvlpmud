#include "/players/pestilence/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;


short_desc = ""+YEL+"Cahara Island Path"+NORM+"";
long_desc =
  "    This is a worn path within the island.  Through the trees to the south,\n"+
  "the sea is barely visible.  Trees and other shrubbery fill this area.  The\n"+
  "path seems to fork, going to the northeast and northwest directions.  The path\n"+
  "leading to the northeast seems less travelled than the nortwest path.\n";
set_light(1);

items = ({
  "path","A small path leading through the trees",
  "trees","Large trees with leaves, reaching up into the sky",
  "shrubbery","Green plants surrounding the path",
});

dest_dir = ({
  "/players/pestilence/Cahara/room/beach.c","south",
  "/players/pestilence/Cahara/room/nwvillage.c","northwest",
  "/players/pestilence/Cahara/room/nepath.c","northeast",
});

}
