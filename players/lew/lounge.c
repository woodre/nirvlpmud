

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Resident Death Office";
	no_castle_flag=0;
	long_desc = 
		"You pass the Resident Death Office on your way to the lounge.\n"
		+ "This is where all the life threatening decisions are made\n"
		+ "for the residences of IIT.  You can see Dana Wilson just\n"
		+ "waiting for someone to bitch out.  Wait, there is a very\n"
		+ "familiar person getting ripped by here now.  Could it be,\n"
		+ "naw. Wait.  Yes!  It's our very own petebre (user name to protect\n"
		+ "the guilty).\n";
	dest_dir = 
	    ({
	"players/lew/res_hall", "north",
	"players/lew/clounge", "south",
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

