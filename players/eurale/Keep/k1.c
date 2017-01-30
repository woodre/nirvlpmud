#include "/players/eurale/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You stand at the base of a huge wall of rock.  Cut into the\n"+
	"rock surface is a doorway with a thick, planked door sealing\n"+
	"the opening.\n";

items = ({
	"wall","This massive stone wall extends upward and disappears\n"+
		"out of sight",
	"doorway","Almost 6 feet wide with jagged edges where the stone\n"+
		"has been chipped away to form it",
	"door","A very heavy, wooden door with no handle or means of\n"+
		"opening it.  The metal strips that hold the pieces of\n"+
		"planking together add additional strength to this\n"+
		"formidable barrier",
});

dest_dir = ({
	"players/eurale/RMS/warp.c","warp",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("touch","touch");
}

search(str) {
 if(!str) { write("What are you trying to search?\n"); return 1; }
 if(str == "door") {
  write("You run your hand across the large wooden door and...\n"+
        "OUCH... you get a large sliver in your palm...\n");
  this_player()->heal_self(-random(15));
  return 1; }
 if(str == "doorway") {
  write("You carefully inspect the stone doorway and find a curious\n"+
        "stone that is loose.  Maybe you should [touch stone].\n");
  return 1; }
}

touch(str) {
 if(!str) { write("Touch?\n"); return 1; }
 if(str == "stone") {
  this_player()->move_player("disappears#players/eurale/Keep/k2.c");
 return 1; }
}
