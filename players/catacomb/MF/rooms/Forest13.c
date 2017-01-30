inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("A dead end in Meserir Forest");
set_long(
"  The area is filled with corpses of past adventurers.  Many have\n"+
"entered the forest but very few have made it back out.  The corpses\n"+
"are all in one large pile next to the dead trees.  The stench of \n"+
"death pervades the area and the reek of the undead lurks around \n"+
"every tree.  The trees to the south and east prevent movement beyond\n"+
"them.\n");

items = ({
	"area",
	"Piles of corpses are scattered throughout the area",
	"corpse",
	"The corpses looked drained of all flesh",
	"corpses",
	"The corpses looked drained of all flesh",
	"pile",
	"The corpses looked drained of all flesh",
	"piles",
	"The corpses looked drained of all flesh",
	"trees",
	"The dead trees block passage to the east and south"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest10.c","north",
	"/players/catacomb/MF/rooms/Forest12.c","west"
	});

}
