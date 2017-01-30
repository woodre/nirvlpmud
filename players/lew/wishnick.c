

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Wishnick";
	no_castle_flag=0;
	long_desc = 
		"Untill i get the history, this is the description of Wishnick\n";
	dest_dir = 
	    ({
	"players/lew/perlstein", "east",
	});
}

query_light() {
    return 1;
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

