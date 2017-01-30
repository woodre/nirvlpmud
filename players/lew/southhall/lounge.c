

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Third south lounge";
	no_castle_flag=0;
	long_desc = 
		"This is the floor lounge.  The furniture has been removed\n"
		+ "after housing decided that the residence here damaged it, which\n"
		+ "is not true.  The furniture that was here was old as hell\n"
		+ "and falling apart to the touch, well, our touch anyway.\n";
	dest_dir = 
	    ({
	"players/lew/southhall/tfloor.c","north",
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

