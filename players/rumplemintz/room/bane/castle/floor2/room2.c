inherit "room/room";
reset(arg){
        if(!present("barbarian")){
       move_object(clone_object("players/rumplemintz/mon/bane/skbarb"), this_object());
        }
        if(!arg){
        set_light(1);
        short_desc="A Corridor";
        long_desc="Yup, you're still in the drab hallway, better get used to it, cause\n"+
                "that's all there is up here on the second level.\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor2/room1","southwest",
                "players/rumplemintz/room/bane/castle/floor2/room3","east",
        });
        }
}
