inherit "room/room";
int i;
reset(arg){
        if(!present("barbarian")){
                for(i=0;i<2;i++){
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
                "players/rumplemintz/room/bane/castle/floor1/room11","east",
                "players/rumplemintz/room/bane/castle/floor1/room2","northwest",
                "players/rumplemintz/room/bane/castle/floor1/room3","north",
                "players/rumplemintz/room/bane/castle/floor1/room4","northeast",
                "players/rumplemintz/room/bane/castle/floor1/room9","west",
                "players/rumplemintz/room/bane/castle/floor1/room16","southwest",
                "players/rumplemintz/room/bane/castle/floor1/room17","south",
                "players/rumplemintz/room/bane/castle/floor1/room18","southeast",
        });
        }
}
