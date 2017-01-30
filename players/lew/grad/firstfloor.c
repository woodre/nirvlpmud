

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "First Grad";
	no_castle_flag=0;
	long_desc = 
		"You enter through some large glass doors designed to make people think\n"
		+ "that this place is really up to date\n"
		+ "when really this place is just a glorified prison.  Go ahead\n"
		+ "look around.  You may find people you know.\n";
	dest_dir = 
	    ({
	"players/lew/res_hall", "west",
/*
	"players/lew/grad/stair1", "up",
*/
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

