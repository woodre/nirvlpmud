inherit "room/room";
reset(arg){
        if(!present("cube")){
        move_object(clone_object("players/dersharp/armors/cube"),this_object());
	}
        if(!arg){
        set_light(1);
        short_desc="A depression";
	long_desc= "	You scramble into this depression to see what is hidden there!\n";
	 dest_dir=({
                "players/dersharp/pillars/room48.c","up",
                });
        }
        }
