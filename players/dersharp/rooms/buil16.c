inherit "room/room";
reset(arg) {
	if(!arg) {
	set_light(1);
	short_desc="Crossroads";
	long_desc="	You hurry your way to the crossroads to examine\n"+
		  "the other corridors.  To the west and to the east\n"+
		  "extends a corridor that seems to contain offices for\n"+
		  "head professors.  To the north is where the classrooms\n"+
		  "are located.  To the south you see the entrance and\n"+
		  "the way back to the city.\n";
	dest_dir=
	({
		"players/dersharp/rooms/buil15.c","west",
		"players/dersharp/rooms/buil10.c","north",
		"players/dersharp/rooms/buil17.c","east",
		"players/dersharp/rooms/entrance.c","south",
	});
}
}
