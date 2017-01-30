inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short("On the bank of a pond");
set_long(
 " A large pond is placed to the south.  The elves from the Shamot\n"+
 "village come here to reflect upon their lives as well as cool off\n"+
 "during the scorching summer days.  Across the pond about halfway \n"+
 "a thick fog devours all the light.  Noone who has ever swam in the\n"+
 "pond has ever gone out more than a quarter of the way, for fear of\n"+
 "dying.  To the north a small clearing can be seen.  A path leads \n"+
 "off to the west.  The bank continues to the east.\n");

items = ({
	"path",
	"A simple dirt path leads off to the west",
	"clearing",
	"A small serene clearing is to the north",
	"pond",
	"The pond is roughly 50 feet across with a thick fog enveloping in the middle",
	"bank",
	"The bank of the pond continues to the east"
	});
dest_dir = ({
	"/players/catacomb/MF/rooms/Creek4.c","clearing",
	"/players/catacomb/MF/rooms/Creek3.c","path",
	"/players/catacomb/MF/rooms/Creek6.c","bank"
	});
}
