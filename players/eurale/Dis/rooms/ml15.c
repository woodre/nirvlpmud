#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("anastasia")) {
  move_object(clone_object("players/eurale/Dis/rooms/NPC/tasia"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Cottage";
long_desc =
	"  This is the bedroom of the daughter Anastasia.  A large brass \n"+
	"bed fills most of the room.  A large dresser with an attached\n"+
	"mirror sits against the wall.  There is a lamp on the dresser \n"+
	"and a chair to sit in.\n";

items = ({
	"bed","This large bed with brass headboard and footboard is done \n"+
		"in greens with thick blankets and large pillows",
	"dresser","A large, wood, desk like dresser with drawers",
	"mirror","A long retangular mirror",
	"lamp","A small oil lamp",
	"chair","A straight-backed wooden chair",
});

dest_dir = ({
	"players/eurale/Dis/rooms/ml12.c","north",
});

}
