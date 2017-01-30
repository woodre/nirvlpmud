inherit "room/room";
reset(arg) {
	if(!arg){
	set_light(1);
	short_desc="College Street";
	long_desc="	You make your way past the students and along a \n"+
		  "well-traveled walkway to the north.  To the north you see\n"+
		  "Greys University, the biggest and most snooty college\n"+
		  "in this whole world.  The main building is to the north\n"+
		  "while the other buildings are off-limits to all but the\n"+
		  "students, which you don't happen to be..\n";
	dest_dir=
	({
		"players/dersharp/rooms/grey8.c","south",
		"players/dersharp/rooms/grey-2.c", "north",
	});
}
}
