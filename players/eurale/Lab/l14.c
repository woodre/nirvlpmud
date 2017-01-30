#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("crawler")) {
  move_object(clone_object("/players/eurale/Lab/NPC/crawler.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  The crack in the sandstone tapers away to nothingness as it goes\n"+
  "deeper into the stone.  Bits of stone crumble and fall as the top of\n"+
  "crack is trouched.  There is very little room to manuever here other\n"+
  "than to retreat the way you came in.\n";

items = ({
  "crack","A narrow fault in the huge sandstone surrounding you",
  "bits","Small pieces, like sand, that have broken from the "+
         "surrounding stone",
});

dest_dir = ({
  "players/eurale/Lab/l12.c","crack",
});

}

realm() { return "NT"; }
