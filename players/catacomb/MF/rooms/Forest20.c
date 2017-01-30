inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  The forest opens up into the stench of a marsh.  The ground starts\n"+
"to swallow anything that treads on it.  Traversing the marsh requires\n"+
"that you must face your worst fears.  The nomad Yeroc is said to have\n"+
"a dwelling deep within the marsh.\n");

items = ({
	"forest",
	"The dying forest is to the north",
	"marsh",
	"The home of Yeroc is deep within the marsh to the south"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest18.c","northwest",
	"/players/catacomb/MF/rooms/Marsh5.c","marsh"
	});

}
