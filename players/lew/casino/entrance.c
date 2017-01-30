

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Casino Entrance";
	no_castle_flag=0;
	long_desc = 
		"Welcome to the Casino Nirvana.\n"
		+ "\n"
		+ "Here you will find many interesting games to play, all of which will\n"
		+ "make you rich (or broke).  There are games for everyone to play.\n"
		+ "This area is still under construction so if you have any ideas, please\n"
		+ "mail Lew and let me know if there is anything you would like to see.\n";
	dest_dir = 
	    ({
	"/players/lew/casino/poker", "north",
	"/players/lew/casino/blackjack", "south",
	"/players/lew/casino/slots", "east",
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

