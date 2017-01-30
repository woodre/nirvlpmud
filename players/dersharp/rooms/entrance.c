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
        short_desc="Entrance to College Building";
	long_desc="	You enter the dimly lit entryway of the building,\n"+
		  "pausing momentarily to let your eyes adjust.  The \n"+
		  "hallway which you are in right now extends beyond \n"+
		  "sight to the north, though you can see other corridors\n"+
		  "breaking off from this one.\n";
	dest_dir=
	({
		"players/dersharp/rooms/grey-2.c", "out",
		"players/dersharp/rooms/buil16.c","north",
	});
}
}
