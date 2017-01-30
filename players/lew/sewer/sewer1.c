

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "The sewer.";
	no_castle_flag=0;
	long_desc = 
          "Welcome to the sludge of Nirvana.  Here you should find a few\n"
		+ "interesting if not disgusting things to kill.  Be very carefull though\n"
		+ "the floors are slippery and you may just slip and fall at the most\n"
		+ "inoportune time.\n";
	dest_dir = 
	    ({
	"/players/lew/sewer/sewer2", "n",
	"/players/lew/sewer", "s",
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

