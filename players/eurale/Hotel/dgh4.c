#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("annie")) {
  move_object(clone_object("players/eurale/Hotel/NPC/annie"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch Hotel office";
long_desc =
	"  You work your way around the counter and find yourself in \n"+
	"the hotel office.  There is a desk and chair sitting on top \n"+
	"of a rather large and worn throw rug.  One large window looks \n"+
	"out of the east wall. \n";

items = ({
	"desk","A large wooden desk where one could work",
	"chair","A comfortable, high-backed wooden chair",
	"rug","A once ornate oriental rug.  It has seen much use",
	"window","This easterly facing window gets lots of morning \n"+
		 "sunshine.  You can see the desert off in the distance",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh2.c","west",
});

}
