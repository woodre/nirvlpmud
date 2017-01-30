inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  The moans of the undead wandering the forest attack from all\n"+
"sides.  The fog devours the life force of all the creatures in\n"+
"the area.  Through the fog nothing can be seen but withering \n"+
"trees.  The paths lead off to the northeast, east, and southwest.\n");

items = ({
	"fog",
	"The fog sucks the life from all that tread through it",
	"trees",
	"The trees wither and die before your eyes",
	"tree",
	"The trees wither and die before your eyes",
	"path",
	"The paths lead off in different directions",
	"paths",
	"The paths lead off in different directions"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest12.c","northeast",
	"/players/catacomb/MF/rooms/Forest16.c","east",
	"/players/catacomb/MF/rooms/Forest19.c","southwest"
	});
}
