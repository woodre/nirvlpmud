

inherit "room/room";

reset(arg) {

	set_light(0);
	short_desc = "A room";
	no_castle_flag=0;
	long_desc = 
		"If you are in here, there is something wrong.\n";
	dest_dir = 
	    ({
	});
}

query_light() {
    return 0;
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

