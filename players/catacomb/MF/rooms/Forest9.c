inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Meserir Forest");
set_long(
"  Everything appears dream-like in the heavy fog.  The trees have\n"+
"a kind of death aura around them.  The branches bend down and almost\n"+
"touch the ground.  With each step the ground wails in protest at the\n"+
"intruders.  The ground continues to the east, west, north and south.\n");

items = ({
	"fog",
	"The thick fog devours all light from the area",
	"trees",
	"The trees droops to the ground in sorrow",
	"tree",
	"The trees droops to the ground in sorrow",
	"branches",
	"The trees droops to the ground in sorrow",
	"branch",
	"The trees droops to the ground in sorrow",
	"ground",
	"The muddy ground wails as each adventurer travels it"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest8.c","west",
	"/players/catacomb/MF/rooms/Forest5.c","north",
	"/players/catacomb/MF/rooms/Forest10.c","east",
	"/players/catacomb/MF/rooms/Forest12.c","south"
	});
}
