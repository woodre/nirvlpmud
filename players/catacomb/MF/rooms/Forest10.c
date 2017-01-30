inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  The ground reaches up from beneath trying to devour all who\n"+
"tread upon it.  With each passing step it hungers for more living\n"+
"souls to add to its collection.  All the roots from the limited \n"+
"vegetation have succumb to the sadness of this place.  \n");

items = ({
	"ground",
	"The ground seems to hunger for your life force",
	"roots",
	"From the look of the vegetation this place devours all forms of life",
	"root",
	"From the look of the vegetation this place devours all forms of life",
	"vegetation",
	"From the look of the vegetation this place devours all forms of life"
	});
dest_dir = ({
	"/players/catacomb/MF/rooms/Forest9.c","west",
	"/players/catacomb/MF/rooms/Forest6.c","north",
	"/players/catacomb/MF/rooms/Forest7.c","northeast",
	"/players/catacomb/MF/rooms/Forest13.c","south",
	"/players/catacomb/MF/rooms/Forest14.c","southeast"
	});
}
