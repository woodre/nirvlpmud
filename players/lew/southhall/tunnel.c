

inherit "room/room";

reset(arg) {

	set_light(-1);
	short_desc = "Under IIT [u]";
	no_castle_flag=0;
	long_desc = 
		"This is one of the tunnels under the residence halls.\n"
		+ "It's dark.  It's dreary.  It bassically lives up to the rest of \n"
		+ "the residence halls.\n";
	dest_dir = 
	    ({
	"players/lew/southhall/firstfloor", "up",
	"players/lew/southhall/tunnel2", "east",
	});
}

query_light() {
    return -1;
}
query_room_maker() {
	return 1;
}

/*
	remove the comments around the "room is modified()" code
	below to prevent changes you have done to this room to
	to be lost useing the roommaker
*/
/*
room_is_modified() {
	return 1;
}
*/
/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

