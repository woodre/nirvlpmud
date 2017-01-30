inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short("Entrance to Mesirer Forest");
set_long(
 " The fog is very thick here making it almost blinding.  Noises\n"+
 "can be heard from all directions.  The legends of this place\n"+
 "seem to be all too true.  Through the fog, weeping willows can\n"+
 "be seen drooping down, adding to the gloom of the forest.  The \n"+
 "bridge to the north looks like it is about to fall apart.  The\n"+
 "foliage opens up to the west, southwest and southeast.\n");

items = ({
	"fog",
	"The fog is the thickest you have ever seen, very little can be seen through it",
	"willows",
	"The weeping willow fit this place all too well",
	"weeping",
	"The weeping willow fit this place all too well",
	"willow",
	"The weeping willow fit this place all too well",
	"trees",
	"The weeping willow fit this place all too well",
	"tree",
	"The weeping willow fit this place all too well",
	"forest",
	"The forest is the epitimy of sadness",
	"bridge",
	"The bridge is several rotted planks attached to each other by an aging rope",
	"planks",
	"Several rotted pieces of wood",
	"plank",
	"Several rotted pieces of wood",
	"rope",
	"The rope is badly aged and frayed",
	"foliage",
	"The foliage opens up to the west, southwest, and southeast"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Creek3.c","bridge",
	"/players/catacomb/MF/rooms/Forest2.c","west",
	"/players/catacomb/MF/rooms/Forest3.c","southwest",
	"/players/catacomb/MF/rooms/Forest4.c","southeast"
	});
}
