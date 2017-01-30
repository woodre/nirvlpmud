inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  Loud wails can be heard throughout the area.  The trees droop\n"+
"down in mourning at the death cries of the spirits.  Everything\n"+
"appears in a haze from the fog.  It almost seems surreal in this\n"+
"dreaded forest.  A path leads off to the southeast, east and north.\n");

items = ({
	"trees",
	"The trees droop down to the ground in mourning for the lost souls",
	"trees",
	"The trees droop down to the ground in mourning for the lost souls",
	"fog",
	"The fog makes everything appear in a haze",
	"forest",
	"The forest looks to make you a permanent resident"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest4.c","north",
	"/players/catacomb/MF/rooms/Forest9.c","east",
	"/players/catacomb/MF/rooms/Forest12.c","southeast"
	});
}
