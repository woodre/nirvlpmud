#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("cinderella")) {
  move_object(clone_object("players/eurale/Dis/rooms/NPC/cinder"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Cottage";
long_desc =
	"  This is the bedroom of the stepdaughter, Cinderella.  A small\n"+
	"bed is nestled in the corner.  A chair sits against the wall and \n"+
	"a small chest hugs the end of the bed.\n";

items = ({
	"chair","A straight-backed wooden chair",
	"chest","A curved, top storage chest for personal items",
	"bed","A small wooden bed with wool covers",
});

dest_dir = ({
	"players/eurale/Dis/rooms/ml12.c","down",
});

}
