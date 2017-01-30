inherit "room/room";


reset(arg){
    if(arg) return;
set_light(1);
set_short("A path along a Creek");
set_long(
 "  The green grass on the ground provides a calm serenity. A \n"+
 "small path follows the creek both east and west.  Across the\n"+
 "creek is the dreaded Mesirer Forest.  It seems strange to have\n"+
 "such a change in only 10 feet.  The forest across the creek is\n"+
 "one of utter sorrow and death.  The Shamot steer clear of the\n"+
 "forest for fear of the Yeroc legend.\n");

items = ({
	"ground",
	"The ground is covered in a plush green grass",
	"grass",
	"The ground is covered in a plush green grass",
	"path",	
	"A path leads along the creek to the west and east",
	"fog",
	"The fog is very thick across the creek",
	"creek",
	"A small crystal blue creek is to the south",
	"forest",
	"The dense fog makes it impossible to see into the forest",
	"trees",
	"The fog makes it impossible to see the trees in the forest to the south",
	"tree",
	"The fog makes it impossible to see the trees in the forest to the south"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Creek1.c","west",
	"/players/catacomb/MF/rooms/Creek3.c","east"

}
