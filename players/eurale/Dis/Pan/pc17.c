#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("michael")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/mike"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Never Island";
long_desc =
	"  You stand in a dense forest on the eastern end of Never Island.\n"+
	"You can just make out the water if you look carefully through\n"+
	"the large trees.  One of the larger trees has broken and fallen\n"+
	"over leaving a sizeable stump.\n";

items = ({
	"trees","Big oaks and walnuts",
	"stump","The stump looks suspicious.  Maybe you should try to\n"+
		"thump on it and see what happens",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pc16.c","west",
});

}

init() {
  ::init();
  add_action("thump","thump");
  add_action("sprinkle","sprinkle"); }

sprinkle(str) {
  if(!str) { write("What are you trying to sprinkle?\n"); return 1; }
  if(str == "dust") {
    this_player()->move_player("dust#players/eurale/Dis/Pan/pc13.c");
    return 1; }
return 1;
}

thump(str) {
  if(!str) { write("What is it you want to thump?\n"); return 1; }
  if(str == "stump") {
	this_player()->move_player("stump#players/eurale/Dis/Pan/pc18.c");
	return 1; }
return 1;
}
