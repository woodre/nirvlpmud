inherit "room/room";
int i;
reset(arg) {
        if(!present("student")) {
        for(i=0;i<6;i++) {
           move_object(clone_object("players/dersharp/monsters/student"), this_object());
}
}
	if(!present("professor")) {
	move_object(clone_object("players/dersharp/monsters/prof"),this_object());
}
        if(!arg){
        set_light(1);
        short_desc="Classroom";
        long_desc="	This is the eastern end of the classroom.\n"+
		  "Here is where the professor teaches about the\n"+
		  "pros and cons of thermal underwear in the winter\n"+
		  "A captivating subject to say the least....\n";
	dest_dir=
	({
		"players/dersharp/rooms/buil6.c","west",
		"players/dersharp/rooms/buil2.c","north",
		"players/dersharp/rooms/buil1","northwest",
	});
}
}
