inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  A devoured skeleton leans up against the willow tree to the\n"+
"north.  The only remains of a fallen adventurer.  The sadness\n"+
"of the forest overcame him and the many undead helped him loose\n"+
"his mortal coil.  \n");

items = ({
	"skeleton",
	"An unfortunate explorer who was overcame by the forest",
	"tree",
	"A large willow tree sheltering a devoured skeleton",
	"willow",
	"A large willow tree sheltering a devoured skeleton"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest11.c","northeast",
	"/players/catacomb/MF/rooms/Forest10.c","northwest",
	"/players/catacomb/MF/rooms/Forest18.c","south",
	"/players/catacomb/MF/rooms/Forest17.c","southwest"
	});
}
