inherit "room/room";
int i;
reset(arg) {
        if(!present("student")) {
        for(i=0;i<2;i++) {
           move_object(clone_object("players/dersharp/monsters/student"), this_object());
}
}
        if(!arg){
        set_light(1);
        short_desc="Hallway";
	long_desc="	You stand at the end of the hallway.  Another hall\n"+
		  "branches off to the west while to the east is a large\n"+
		  "classroom.  You can hear a man giving a lecture in the\n"+
		  "classroom, while there is silence to the west.\n";
	dest_dir=
	({
		"players/dersharp/rooms/buil4.c","west",
		"players/dersharp/rooms/buil6.c","east",
		"players/dersharp/rooms/buil10.c","south",
	});
}
}
