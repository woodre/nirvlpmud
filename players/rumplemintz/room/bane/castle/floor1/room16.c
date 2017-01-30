inherit "room/room";
reset(arg){
        if(!present("warrior")){
       move_object(clone_object("players/rumplemintz/mon/bane/skwarr2"), this_object());
        }
        if(!arg){
        set_light(1);
        short_desc="Bane's Castle";
        long_desc="    You are wandering through Bane's castle, notice that in  every\n"+
                "room, there are some of Bane's servants here, making you feel not so\n"+
                "welcome.  You can't help but wonder why they aren't attacking you,\n"+
                "maybe they have something planned...\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor1/room17","east",
                "players/rumplemintz/room/bane/castle/floor1/room8","northwest",
                "players/rumplemintz/room/bane/castle/floor1/room9","north",
                "players/rumplemintz/room/bane/castle/floor1/room10","northeast",
                "players/rumplemintz/room/bane/castle/floor1/room15","west",
                "players/rumplemintz/room/bane/castle/floor1/room22","southwest",
                "players/rumplemintz/room/bane/castle/floor1/room23","south",
                "players/rumplemintz/room/bane/castle/floor1/room24","southeast",
        });
        }
}
