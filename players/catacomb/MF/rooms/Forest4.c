inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Mesirer Forest");
set_long(
 "  As you enter the ground makes a disgusting squish.  The fog\n"+
 "seems to grow hands choking the life out of all who enter.  The\n"+
 "wails of the dead are never ending.  All who have enter this \n"+
 "place have never returned.  Many say that the gloom overtook \n"+
 "them and they became food for the wandering spectres.  A small\n"+
 "rotting sign is placed in the ground.\n");

items = ({
	"fog",
	"The fog acts like a ghoul sucking the life out of everything living",
	"ground",
	"The ground makes a sickening squish sound with each movement",
	"sign",
         "-------------------\n"+
         "|   Abandon all    |\n"+
         "| hope, all ye who |\n"+
         "|      enter       |\n"+
         "-------------------\n"
	});


dest_dir = ({
	"/players/catacomb/MF/rooms/Forest1.c","northwest",
	"/players/catacomb/MF/rooms/Forest5.c","east",
	"/players/catacomb/MF/rooms/Forest3.c","west",
	"/players/catacomb/MF/rooms/Forest8.c","south"
	});

}
