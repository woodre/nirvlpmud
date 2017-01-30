

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Station 1";
	no_castle_flag=0;
	long_desc = 
		"This is the first station of your induction to the Army.  You must visit\n"
		+ "all stations to complete your enlistment.  Failure to do so will result\n"
		+ "in sever punishment.\n";
	dest_dir = 
	    ({
	"/players/lew/army/station2", "station2",
	"/players/lew/army/station3", "station3",
	"/players/lew/army/station4", "station4",
	"/players/lew/army/station5", "station5",
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

