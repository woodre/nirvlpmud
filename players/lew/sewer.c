

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "sewer [church]";
	no_castle_flag=0;
	long_desc = 
		"This is the sewer, chances are you got flushed.\n";
	dest_dir = 
	    ({
	"/room/church", "church",
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

