inherit "room/room";

reset(arg){
    if(arg) return;
set_light(0);
set_short("Mesirer Forest");
set_long(
 "  The fog consumes all the light from the forest.  Some old\n"+
 "trees are placed all around.  The dampened ground makes travel\n"+
 "in any direction a chore.  Small patches of grass can be seen\n"+
 "scattered throughout the area.  A dark feeling of sorrow enters\n"+
 "all who enter into this dreaded forest.  The dirt path leads off\n"+
 "to the northeast, east and to the north.\n");

items = ({
	"fog",
	"The fog consumes everything making it difficult to see",
	"ground",
	"The ground makes a sickening squish sound with each movement",
	"grass",
	"A breed of grass that is very strong to have lived without sun",
	"patch",
	"A breed of grass that is very strong to have lived without sun",
	"patches",
	"A breed of grass that is very strong to have lived without sun",
	"path",
	"The path vears of to the north, east and northeast",
	"trees",
	"Some old trees sit either dead already or dying from diseases",
	"tree",
	"Some old trees sit either dead already or dying from diseases"
	});

dest_dir = ({
	"/players/catacomb/MF/rooms/Forest1.c","northeast",
	"/players/catacomb/MF/rooms/Forest2.c","north",
	"/players/catacomb/MF/rooms/Forest4.c","east"
	});
}
