#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("pig")) {
  move_object(clone_object("players/eurale/Dis/rooms/NPC/pig4"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Stone house";
long_desc =
	"  You have entered a small house made of stone.  The construction\n"+
	"is extremely well done and there are bars anchored into the \n"+
	"mortar surrounding the window openings.  A small table and chair\n"+
	"sit in the center of the building and an ornate oil lamp hangs \n"+
	"from the ceiling overhead.\n";
items = ({
	"table","A polished slab of black walnut, beautiful",
	"chair","A straight-backed, sturdy wooden chair",
	"lamp","A stained-glass original",
});

dest_dir = ({
	"players/eurale/Dis/rooms/pp9.c","west",
});

}
