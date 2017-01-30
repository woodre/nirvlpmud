inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short("On the bank of a pond");
set_long(
 " The bank is covered with small pebbles and sand.  The pond is \n"+
 "large and covered with fog from the middle to the other side.  \n"+
 "The pond surrounds the entire area making a small archipeligo  \n"+
 "with only one way to go, to the bank further to the west.\n");

items = ({
	"pebbles",
	"Small pebbles are scattered around the bank",
	"pebbles",
	"Small pebbles are scattered around the bank",
	"sand",
	"It's sand, nothing special, just sand",
	"pond",
	"The pond is roughly 50 feet across with a thick fog enveloping in the middle to the south",
	"bank",
	"The bank of the pond continues to the west",
	"fog",
	"The fog envelops half of the pond making it impossible to see the other side"
	});
dest_dir = ({
	"/players/catacomb/MF/rooms/Creek5.c","bank"
	});
}
