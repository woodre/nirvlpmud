inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Mesirer Forest");
set_long(
 "  The thick fog makes it impossible to see very far in any direction.\n"+
 "To the north it appears to be a body of water.  The fog prevents anyone\n"+
 "from seeing whether it is a mere creek or a larger pond.  Traversing \n"+
 "into the water is impossible for fear of the drowned spirits.  The path\n"+
 "continues to the east, west and to the south.\n");

items = ({
	"fog",
	"The fog takes away all sense of orientation",
	"water",
	"The fog prevents you from knowing if it is a small stream or a lake",
	"path",
	"The path leads into the forest to the east, west and south"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest5.c","west",
	"/players/catacomb/MF/rooms/Forest7.c","east",
	"/players/catacomb/MF/rooms/Forest10.c","south"
	});

}
