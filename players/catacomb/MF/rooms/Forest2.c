inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short("Mesirer Forest");
set_long(
 "  The creek to the north is a murky brown.  The fog over it\n"+
 "make it impossible to see the other side.  Small torches are\n"+
 "set on the bank of the creek giving off what light they can.\n"+
 "There is very little grass on the ground.  The light from the\n"+
 "sun never reaches the ground to let the the grass show its \n"+
 "true beauty.  Several cattails can be seen along the bank of\n"+
 "the creek.  The dirt path leads off to the east, and south.\n");

items = ({
	"creek",
	"The creek is nothing more than a murky stream",
	"stream",
	"The creek is nothing more than a murky stream",
	"fog",
	"The fog consumes everything making it difficult to see",
	"torches",
	"Small torches can be seen along the path to the east",
	"torch",
	"Small torches can be seen along the path to the east",
	"light",
	"Small torches can be seen along the path to the east",
	"ground",
	"The ground is almost bare from the lack of sun",
	"grass",
	"A breed of grass that is very strong to have lived without sun",
	"cattail",
	"They litter the bank of the creek to the north",
	"cattails",
	"They litter the bank of the creek to the north",
	"bank",
	"They litter the bank of the creek to the north",
	"path",
	"The path vears of to the east and south"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest1.c","east",
	"/players/catacomb/MF/rooms/Forest3.c","south"
	});
}
