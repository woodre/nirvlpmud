inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Mesirer Forest");
set_long(
 "  A large willow tree stands drooping to the ground to the south.\n"+
 "Along its trunk is a well-weathered skull.  An old, rusted-out \n"+
 "axe lies next to the skull.  The ground around it is decayed from\n"+
 "all of the carrion bugs that feasted on this unfortunate adventurer.\n"+
 "The path leads to the west, southeast, and southwest.\n");

items = ({
	"willow",
	"The tree serves as a tombstone for the adventurer",
	"tree",
	"The tree serves as a tombstone for the adventurer",
	"trees",
	"The tree serves as a tombstone for the adventurer",
	"ground",
	"All the vegetation around the skull is gone",
	"vegetation",
	"All the vegetation around the skull is gone",
	"skull",
	"The only remains of an unfortunate treasure hunter",
	"remains",
	"The only remains of an unfortunate treasure hunter",
	"path",
	"The dirt path leads around the giant willow tree"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest6.c","west",
	"/players/catacomb/MF/rooms/Forest11.c","southeast",
	"/players/catacomb/MF/rooms/Forest10.c","southwest"
	});

}
