#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("hook")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/capt"),TO); }
if(!present("smee")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/smee"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Pirate Ship";
long_desc =
	"  This is a massive, 3-masted pirate ship.  The Jolly Roger is\n"+
	"flying proudly from the top of the highest mast.  The poop deck,\n"+
	"main deck and bow deck are all scrubbed and the equipment is \n"+
	"stowed.  You hear a very faint ticking coming from under the \n"+
	"stern of the ship but you would have to jump in the water to\n"+
	"get under there.\n";

items = ({
	"roger","A black flag with a skull and crossed bones",
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("jump","jump");
  add_action("sprinkle","sprinkle"); }

sprinkle(str) {
  if(!str) { write("What are you trying to sprinkle?\n"); return 1; }
  if(str == "dust") {
    this_player()->move_player("dust#players/eurale/Dis/Pan/pc13.c");
    return 1; }
return 1;
}

jump() {
  this_player()->move_player("jump#players/eurale/Dis/Pan/pc14.c");
  return 1; }
