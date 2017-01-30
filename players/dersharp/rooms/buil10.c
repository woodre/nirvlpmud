inherit "room/room";
reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc="Hallway";
	long_desc="	You enter this hallway with a tinge od concern.\n"+
		  "You hear voices coming from the classrooms and \n"+
		  "you realize what building you are in.....The \n"+
		  "Computer Science Building!!!!  When you realize \n"+
		  "this, another odd thought comes to you.....How can\n"+
		  "a medieval city have computers....\n";
	dest_dir=
	({
		"players/dersharp/rooms/buil9.c","west",
		"players/dersharp/rooms/buil16.c","south",
		"players/dersharp/rooms/buil5.c","north",
	});
}
}
