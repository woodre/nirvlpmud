inherit "room/room";
int i;
reset(arg) {
        if(!present("student")) {
        for(i=0;i<3;i++) {
           move_object(clone_object("players/dersharp/monsters/student"), this_object());
}
}
        if(!arg){
        set_light(1);
        short_desc="College Street";
        long_desc="	You stand before the gates to the main building of \n"+
		  "the college.  Students walk in and out of the building\n"+
		  "talking to each other about private things and to one\n"+
		  "side of the door is a man preaching about the end of \n"+
		  "world.  The building itself seems to be a one-level \n"+
		  "office-building, nondescript in every fashion.\n";
	dest_dir=
	({
		"players/dersharp/rooms/entrance.c", "north",
		"players/dersharp/rooms/grey-1.c","south",
	});
}
}
