inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Mesirer Forest");
set_long(
 "  The wailing is almost deafening.  All of the spectres and \n"+
 "wandering spirits become upset when they sense a living being\n"+
 "in their sanctuary.  The trees' branches droop down as they\n"+
 "succumb to the sadness of this place.  The ground screams out\n"+
 "in agony with every step.  The path leads off to the east, west\n"+
 "and south.\n");

items = ({
	"tree",
	"The trees seem to weep with every passing moment",
	"trees",
	"The trees seem to weep with every passing moment",
	"branches",
	"The branches droop down low rotting away in this gloom",
	"branch",
	"The branches droop down low rotting away in this gloom",
	"path",
	"The path leads off into the forest to the south, west and east"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest4.c","west",
	"/players/catacomb/MF/rooms/Forest6.c","east",
	"/players/catacomb/MF/rooms/Forest9.c","south"
	});

}
