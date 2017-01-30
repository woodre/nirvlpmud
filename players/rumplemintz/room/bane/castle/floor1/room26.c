inherit "room/room";
int i;
reset(arg){
        if(!present("barbarian")){
                for(i=0;i<3;i++){
	move_object(clone_object("players/rumplemintz/mon/bane/skbarb"),this_object());
        }
        }
        if(!arg){
        set_light(1);
        short_desc="Bane's Castle";
        long_desc="    You are wandering through Bane's castle, notice that in  every\n"+
                "room, there are some of Bane's servants here, making you feel not so\n"+
                "welcome.  You can't help but wonder why they aren't attacking you,\n"+
                "maybe they have something planned...\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor1/room27","east",
                "players/rumplemintz/room/bane/castle/floor1/room33","south",
                "players/rumplemintz/room/bane/castle/floor1/room34","southeast",
                "players/rumplemintz/room/bane/castle/floor1/room20","northeast",
                "players/rumplemintz/room/bane/castle/floor1/room19","north",
                "players/rumplemintz/room/bane/castle/floor1/room25","west",
                "players/rumplemintz/room/bane/castle/floor1/room18","northwest",
                "players/rumplemintz/room/bane/castle/floor1/room32","southwest",
        });
        }
}
