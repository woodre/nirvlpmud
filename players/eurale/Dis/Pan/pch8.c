#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("tinkerbell")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/tinker"),TO); }
if(!present("nana")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/nana"),TO); }
if(!present("john")) {
  move_object(clone_object("players/eurale/Dis/Pan/NPC/john"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Brownstone House";
long_desc =
	"  At the top of the stairs is the bedroom of the Darling \n"+
	"children, Wendy, John and Michael.  You can often times find\n"+
	"their beloved pet, Nana, here with them.  There are 3 cozy \n"+
	"beds, a large chest of drawers and a window to let in both \n"+
	"air and light.\n";

items = ({
	"window","A large window that looks out on the park across the\n"+
		"street",
	"beds","Cozy beds covered with down quilts and fluffy pillows",
	"chest","A chest with 3 very large drawers, one for each child",
});

dest_dir = ({
	"players/eurale/Dis/Pan/pch3.c","down",
});

}

init() {
  ::init();
  add_action("sprinkle","sprinkle"); }

sprinkle(str) {
  if(!str) { write("What are you trying to sprinkle?\n"); return 1; }
  if(present("tinkerbell") && (str == "dust")) {
    this_player()->move_player("dust#players/eurale/Dis/Pan/pc13.c");
    return 1; }

  else {
    if(!present("tinkerbell")) {
    write("Tinkerbell is not around with her dust.\n"); return 1; }
    return 1; }
return 1;
}
