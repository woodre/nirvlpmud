inherit "room/room";
int i;
reset(arg) {
        if(!present("student")) {
        for(i=0;i<4;i++) {
           move_object(clone_object("players/dersharp/monsters/student"), this_object());
}
}
        if(!arg){
        set_light(1);
        short_desc="Classroom";
	long_desc="	You enter a large classroom with only around\n"+
		  "24 students in it.  In this section of the room is\n"+
		  "desks and chairs indicative of a classroom.\n";
	dest_dir=
	({
		"players/dersharp/rooms/buil5.c","west",
		"players/dersharp/rooms/buil1.c","north",
		"players/dersharp/rooms/buil7.c","east",
	});
}
}
