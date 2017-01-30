#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";
int ONE;  /*  only one person  */

reset(arg) {
  if(arg) return;
set_light(1);
ONE = 0;  /* nobody in space  */

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"You are on a curved stone stairway.  It is narrow and fairly\n"+
	"steep.  Off to the side, cut into the wall of stone is a small\n"+
	"alcove that looks too small for anyone to fit in.  The stair-\n"+
	"way continues both up and down.  The sound of silence echoes\n"+
	"from down below.\n";

items = ({
	"stairway","A narrow, dark, steep curved stairway cut into the\n"+
		"stone.  The slime from the dripping water makes the\n"+
		"steps slippery and the footing treacherous",
	"alcove","A small hole cut into the rock that might have been\n"+
		"the begining of another tunnel but the going was just\n"+
		"too tough so it was abandoned.  The hole is too dark\n"+
		"to see all the way to the rear but you might be able to\n"+
		"climb in and get a complete look",
});

dest_dir = ({
	"players/eurale/Keep/k24.c","down",
	"players/eurale/Keep/k21.c","up",
});

}

set_ONE(i) { ONE = i; }
query_ONE() { return ONE; }


init() {
  ::init();
  add_action("climb","climb");
  add_action("listen","listen");
}

climb(str) {
if(!str) { write("Climb?\n"); return 1; }
if(str == "in") { write("I'm not sure what you mean.\n"); return 1; }
if(str == "alcove" && ONE == 0) {
  write("You get down on your hands and knees and crawl into the hole..\n");
  say(tpn+" crawls into the hole...\n");
  this_player()->move_player("alcove#players/eurale/Keep/k26.c");
  ONE = 1;  /*  space is full  */
  return 1; }
else {
  write("You try to crawl into the alcove only to find that you just\n"+
	"won't fit.....\n");
  return 1; }
}

listen(str) {
if(!str) { write("What would you listen to?\n"); return 1; }
if(str == "sound" || str == "silence") {
  write("You listen intently.... it's so quiet it's eerie..\n");
  say(tpn+" listens for noises...\n");
  return 1; }
}
