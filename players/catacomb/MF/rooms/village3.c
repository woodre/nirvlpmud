inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short(BOLD+GRN+"Shamot village"+NORM);
set_long(
"  The roads of Shamot village pass by the statue of Sylvanus to\n"+
"the east.  The trees reach high overhead.  The sun glistens off\n"+
"the leaves in the midday sun.  The road is filled with the hustle\n"+
"and bustle of a regular town.\n");

items = ({
	"trees",
	"The many trees reach to the sky trying to get closer to their life",
	"tree",
	"An ancient tree that has been here since the days when the Shamot first arrived",
	"leaves",
	"The leaves give off extra light throughout the village",
	"leaf",
	"It is impossible to only look at one leaf when you are so far below the tree",
	"sun",
	"Are you trying to blind yourself, don't look into the sun",
	"statue",
	"The statue is a vision of the Shamot's view of their god, Sylvanus",
	"sylvanus",
        "The god of the forests, and the only god the Shamot worship",
        "road",
        "The road is a dirt path leading through the village"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/village6.c","northeast",
	"/players/catacomb/MF/rooms/village2.c","southeast"
	});
}
