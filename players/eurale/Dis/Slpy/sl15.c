#include "DEFS.h"
inherit "room/room";
int p4;

reset(arg) {
p4 = 1;

if(!present("horseman")) {
  move_object(clone_object("players/eurale/Dis/Slpy/NPC/headless"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Shade Lane";
long_desc =
	"  The lane travels through the twisted forest here.  The large\n"+
	"old trees with their roots sticking up out of the ground and \n"+
	"their gnarly bark make them often look like sinister figures.\n"+
	"Their huge branches block out the sun making it a dark and\n"+
	"forboding place.\n";
items = ({
	"trees","Very old hardwoods",
	"branches","Large branches that overhang the lane",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl14.c","east",
	"players/eurale/Dis/Slpy/sl17.c","west",
});

}

init() {
  ::init();
  add_action("search","search");
}

search(str) {
object ob;
  ob = present("horseman");
  if(ob) {
  write("The horseman throws something at you!\n"); return 1; }

if(!str) { write("What are you trying to search?\n"); return 1; }
if(str == "roots") {
if(!present("horseman") && (p4 == 1)) {
  write("You search beneath the old roots and find a puzzle piece.\n");
  move_object(clone_object("players/eurale/Dis/misc/puz4.c"),
	this_player());
  p4 = 0;
  return 1; }

if(!present("horseman") && (p4 == 0)) {
  write("You search beneath the old roots and find nothing but worms.\n");
  return 1; }
 return 1; }
return 1;
}
