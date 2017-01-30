inherit "room/room";
int i;
reset(arg){
        if(!present("warrior")){
                for(i=0;i<3;i++){
       move_object(clone_object("players/rumplemintz/mon/bane/skwarr2"), this_object());
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
                "players/rumplemintz/room/bane/castle/floor1/room14","east",
                "players/rumplemintz/room/bane/castle/floor1/room20","south",
                "players/rumplemintz/room/bane/castle/floor1/room21","southeast",
                "players/rumplemintz/room/bane/castle/floor1/room7","northeast",
                "players/rumplemintz/room/bane/castle/floor1/room6","north",
                "players/rumplemintz/room/bane/castle/floor1/room12","west",
                "players/rumplemintz/room/bane/castle/floor1/room5","northwest",
                "players/rumplemintz/room/bane/castle/floor1/room19","southwest",
        });
        }
}
