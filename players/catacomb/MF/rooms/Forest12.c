inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  The moans from the west give an eerie feeling to this\n"+
"area.  The moans make everyone who hears them run in terror\n"+
"from them.  One can only imagine what kind of horrors lie\n"+
"deeper in the forest.  The lack of light adds to the creepy\n"+
"feeling of the forest.\n");

items = ({
	"light",
	"No light is able to shine through the fog",
	"fog",
	"The thick fog prevents any light from entering"
	});
dest_dir = ({
	"/players/catacomb/MF/rooms/Forest8.c","northwest",
	"/players/catacomb/MF/rooms/Forest9.c","north",
	"/players/catacomb/MF/rooms/Forest13.c","east",
	"/players/catacomb/MF/rooms/Forest15.c","southwest",
	"/players/catacomb/MF/rooms/Forest16.c","south"
	});
}
