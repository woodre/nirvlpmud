#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("pig")) {
  move_object(clone_object("players/eurale/Dis/rooms/NPC/pig2"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Stick house";
long_desc =
	"  You have entered a small house made of sticks.  The construction\n"+
	"is pretty loose and it doesn't appear to be very stable.  There \n"+
	"is a small wooden table with one chair and an oil lamp sitting \n"+
	"on the table.\n";
items = ({
	"table","A small wooden table for eating",
	"chair","This is closer to a stool but very short",
	"lamp","An oil lamp, lighted and half full of oil",
});

dest_dir = ({
	"players/eurale/Dis/rooms/pp5.c","south",
});

}