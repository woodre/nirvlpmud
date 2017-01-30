inherit "room/room";

reset(arg){
    if(arg) return;
set_light(1);
set_short("A path along a Creek");
set_long(
 " The crystal clear creek babbles by to the south and flows into\n"+
 "a large pond to the east.  Small bushes can be seen to the north\n"+
 "along the path.  A bridge crosses the creek into the darkness of\n"+
 "Mesirer Forest.  The path continues to an opening to the northeast,\n"+
 "east, and west.\n");

items =({
	"path",
	"A path leads along the creek to the northeast, west and east",
	"fog",
	"The fog is very thick across the creek",
	"creek",
	"A small crystal blue creek is to the south,
	"pond",
	"The creek flows into a large pond further to the east",
	"bushes",
	"Some some bushes can be seen along the path",
	"bridge",
	"The bridge appears to be made well",
	"forest",
	"The dense fog makes it impossible to see into the forest"
	});
dest_dir = ({
	"/players/catacomb/MF/rooms/Creek2.c","west",
	"/players/catacomb/MF/rooms/Creek4.c","clearing",
	"/players/catacomb/MF/rooms/Creek5.c","east",
	"/players/catacomb/MF/rooms/Forest1.c","bridge"
}
