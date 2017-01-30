

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Cohen Lounge";
	no_castle_flag=0;
	long_desc = 
		"This is beautiful Cohen lounge.  It has been recently refurbished,\n"
		+ "with dorkey looking furniture that cost the residence thousands,\n"
		+ "a piano that hasen't been tuned in about a hundred years,\n"
		+ "and a handfull of pissed off students. (not aggressive this time,\n"
		+ "but feel free to put them out of their misery.\n";
	dest_dir = 
	    ({
	"players/lew/lounge", "north",
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

