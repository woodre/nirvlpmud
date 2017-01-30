inherit "room/room";
int i;
reset(arg) {
        if(!present("assistant")) {
        for(i=0;i<2;i++) {
           move_object(clone_object("players/dersharp/monsters/assistant"), this_object());
}
}
        if(!arg){
        set_light(1);
        short_desc="Office";
	long_desc="	You enter this room slowly, seeing two desks on\n"+
		  "either side of a large door to the west.  They are \n"+
		  "rather small yet they are holding a great bulk of \n"+
		  "papers.  As you look closer at the papers you see\n"+
		  "the famailiar red-ink of teaching assistants....\n"+
		  "You seem to hear giggling from the next room..\n";
	dest_dir=
	({
		"players/dersharp/rooms/buil3.c","west",
		"players/dersharp/rooms/buil5.c","east",
	});
}
}
init(){
	::init();
	add_action("west","west");
	}
west() {
	if(present("assistant")){
	write("The assistants will not let you by!\n");
	return 1;
	}
	return 0;
	}
