#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  This small rise slopes down to a sandy looking area below.  The\n"+
  "solid rock to the southeast gives way to a softer looking sandstone\n"+
  "that curves around you like a pocket.  A huge root hangs out of the\n"+
  "wall above the irregular indentation near the floor.\n";

items = ({
  "indentation","It appears to be a small, irregular indentation that\n"+
                "one might be able to crawl into",
  "area","A sandy looking floor surrounded by brownish rock",
  "rock","Grey rock layered with brown",
  "sandstone","Tan in color and very gritty",
  "root","A large dead root from a tree long dead.  It covers a\n"+
         "narrow crack in the sandstone behind it",
  "crack","A split in the sandstone that looks like one could slide "+
          "through",
});

dest_dir = ({
  "players/eurale/Lab/l12.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("crawl","crawl");
  add_action("slide","slide");
}

crawl() {
  write("You get down on all fours and crawl through the indentation.\n");
  TP->move_player("crawling#players/eurale/Lab/l7.c");
return 1; }

slide(str) {
if(!str) { write("Slide?\n"); return 1; }
if(str == "crack") {
  write("You slide through the narrow crack.\n");
  TP->move_player("through the crack#players/eurale/Lab/l11.c");
  return 1; }
}
