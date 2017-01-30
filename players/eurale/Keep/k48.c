#include "/players/eurale/defs.h"
inherit "room/room";
int here;

reset(arg) {
  if(arg) return;
here = 1;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You are standing in almost thigh-deep swamp water.  The\n"+
	"bottom is soft and squishy, making moving hard.  The cavern\n"+
	"echoes the splashing you make as you move through the water.\n"+
	"You can feel the edge of some sort of depression on the bottom\n"+
	"and your leg brushes against some sort of 'thing' as you inch\n"+
	"along the rim of what seems like a large underwater hole.\n";

items = ({
	"water","Dark brownish-green, you can't see through it",
	"cavern","A large bubble in this huge stone.  It has relatively\n"+
		"smooth sides and extends farther than you can see",
	"thing","The water is too murky and there isn't enough light\n"+
                "to see but you might be able to feel it with your foot",
});

dest_dir = ({
	"players/eurale/Keep/k45.c","east",
});

}

init() {
  ::init();
  add_action("east","east");
  add_action("feel","feel");
}

feel(str) {
if(!str) { write("What are you trying to feel?\n"); return 1; }
if(str == "object" && here == 0) {
  write("You feel with your foot.... it feels like a tree limb..\n");
  return 1; }
if(str == "thing" && here == 1) {
  write("You feel with your foot and the object moves.....\n"+
   BOLD+"SOMETHING"+NORM+" grabs a hold of your leg....\n\n");
  move_object(clone_object("players/eurale/Keep/NPC/wyndlass"),TO);
  here = 0;
  return 1; }
}

east() {
if(present("wyndlass")) {
  write("A huge tentacle grabs you and pulls you back as you try to flee..\n");
  say("A huge black tentacle grabs "+capitalize(TPRN)+" and pulls them back..\n");
  return 1; }
if(!present("wyndlass")) {
  this_player()->move_player("east#players/eurale/Keep/k45.c");
  return 1; }
}
