#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  Solid rock surrounds you.  The closeness of the walls leaves you\n"+
  "barely enough room to turn around.  Deep shadows hide most of the\n"+
  "walls and there is a strange indentation near the floor on the end\n"+
  "wall.  The area is so quiet it almost seems like you can hear the\n"+
  "whisper of a slight breeze much like a sea shell held to your ear.\n";

items = ({
  "rock","Dense grey stone, chipped away leaving jagged edges",
  "walls","Solid rock, cut through layered stone",
  "shadows","Blackness hiding whatever is there",
  "indentation","It appears to be a small, irregular indentation that\n"+
                "one might be able to crawl into",
});

dest_dir = ({
  "players/eurale/Lab/l8.c","south",
  "players/eurale/Lab/l6.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("search","search");
  add_action("crawl","crawl");
  add_action("climb","climb");
}

crawl() {
  write("You get down on all fours and crawl through the indentation.\n");
  TP->move_player("crawling#players/eurale/Lab/l10.c");
return 1; }

search(str) {
if(!str) { write("Search what?\n"); return 1; }
if(str != "shadows") {
  write("You search the "+str+" but find nothing.\n");
  return 1; }
write("As you search the blackness, you find a small ledge you think\n"+
      "you could climb up on.\n");
return 1; }

climb(str) {
if(!str || str == "ledge") {
  write("You carefully climb up onto the narrow ledge.\n");
  TP->move_player("into the shadows#players/eurale/Lab/l9.c");
  return 1; }
}
