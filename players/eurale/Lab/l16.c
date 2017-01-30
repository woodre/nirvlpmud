#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  Wisps of moisture slowly rise as the warm water contacts the cool\n"+
  "rock.  The flat platform disappears into the darkness under the\n"+
  "back wall.  There is an eerie stillness in the air here.\n";

items = ({
  "wisps","Like the mist rising off a lake in the fall",
  "rock","Flat and greenish brown, a small shelf-like formation",
  "wall","A vertical wall that looks to be eroded away near its base",
  "darkness","Very dark but as your eyes adjust it appears that the\n"+
             "wall has been eroded way to the south and west from\n"+
             "constant water lapping.  A small person might even be\n"+
             "able to crawl back under",
});

dest_dir = ({
  "players/eurale/Lab/l15.c","water",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("crawl","crawl");
}

crawl(str) {
if(!str) { write("Crawl where?\n"); return 1; }
if(str == "west") {
  write("You crouch way down and crawl west.\n");
  TP->move_player("under the ledge#players/eurale/Lab/l17.c");
  return 1; }
if(str == "south") {
  write("You duck your head down and crawl south.\n");
  TP->move_player("under the ledge#players/eurale/Lab/l18.c");
  return 1; }
}
