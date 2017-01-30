

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "The sewer.";
	no_castle_flag=0;
	long_desc = 
		"As you go deeper into the sewer the light begisns to dim.  If you \n"
		+ "don't have a torch, you may want to go back and get one.\n"
		+ "Before you lies a great tunnel of darkness.  Are you sure you want\n"
		+ "to continue???\n";
	dest_dir = 
	    ({
	"/players/lew/sewer/sewer3", "n",
	"/players/lew/sewer/sewer1", "s",
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

