

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Station 2";
	no_castle_flag=0;
	long_desc = 
		"This is the central issue facility.  Here you will recieve all of the\n"
		+ "equipment that you will need in order to survive Basic Training and\n"
		+ "your future career in the military.\n";
	dest_dir = 
	    ({
	"/players/lew/army/station1", "n",
	"/room/church", "exit",
	"/players/lew/army/station1", "station1",
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

