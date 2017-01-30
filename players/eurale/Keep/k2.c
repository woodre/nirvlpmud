#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You stand at the bottom of a short flight of stairs.  The stone\n"+
	"has been chipped away leaving caverns that run off in multiple\n"+
	"directions.  There are burning torches lighting the passageways\n"+
	"but the light doesn't penetrate this deep darkness very far.\n"+
	"Water slowly drips from the ceiling and runs in small rivulets\n"+
	"down the stoney walls.\n";

items = ({
	"stairs","Five steps carved from the rock",
	"torches","Wooden handles with lighted packing on the end.\n"+
		"One of the torches seems to be loose, maybe you should\n"+
		"give it a twist and see what happens",
});

dest_dir = ({
	"players/eurale/Keep/k1.c","up",
	"players/eurale/Keep/k19.c","south",
	"players/eurale/Keep/k3.c","east",
	"players/eurale/Keep/k51.c","west",
});

}

init() {
  ::init();
  add_action("twist","twist");
}

twist(str) {
if(!str) { write("Twist what?\n"); return 1; }
if(str == "torch") {
  write("The torch moves silently and you hear a slight grating...\n");
  say(tpn+" adjusts the torch...\n");
  this_player()->move_player("darkness#players/eurale/Keep/k61.c");
  return 1; }
}
