#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("dragon")) {
move_object(clone_object("players/eurale/Keep/NPC/green_dragon"),TO); }
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"This is a natural nook formed by the splitting rock.  It only\n"+
	"allows one way in and out and is thus easily protected against\n"+
	"outside intrusion.  The solid rock surrounding the small cavern\n"+
	"makes it an impenitrable and safe resting spot.\n";

items = ({
	"floor","Solid rock and smooth",
	"rock","Dense, gray rock with few colors",
});

dest_dir = ({
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("wedge","wedge");
  add_action("search","search");
}

search(str) {
if(!str || str == "rock") {
  write("You search the rock walls and find a crevass that you might\n"+
	"be able to wedge your way out through.\n");
  return 1; }
}

wedge(str) {
if(!str) { write("Wedge where?\n"); return 1; }
if(str == "crevass") {
  write("You wedge yourself into the crevass and work your way back out\n"+
	"into the open spaces.\n");
  TP->move_player("out#players/eurale/Keep/k59.c");
  ("/players/eurale/Keep/k59.c")->set_ONE(0);
  return 1; }
}
