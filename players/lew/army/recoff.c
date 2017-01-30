

inherit "room/room";

reset(arg) {

	set_light(1);
	short_desc = "Recruiting Office";
	no_castle_flag=0;
	long_desc = 
		"This is the Army recruiting office.  Here is where you will sign your life\n"
		+ "away.  There are a couple of people in here that you think should just\n"
		+ "give up on life and die (they already smell like they did).  Sitting\n"
		+ "around are a couple of NCO's just laughing and having a good time, after\n"
		+ "all, there really is nothing else they can do.\n";
	dest_dir = 
	    ({
	"/players/lew/army/station1", "n",
	"/room/church", "exit",
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

init() {
    ::init();
      add_action("join");add_verb("join");
}
