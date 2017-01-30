inherit "room/room";
reset(arg){
	if(!present("ring")){
	move_object(clone_object("players/dersharp/armors/ring"),this_object());
	}
	if(!arg){
	set_light(1);
	short_desc="A depression";
	long_desc= "	You scramble down into the depression to find what\n"+
                   "is down there.\n";
	dest_dir=({
		"players/dersharp/pillars/room2.c","up",
		});
	}
	}
