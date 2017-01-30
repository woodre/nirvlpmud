inherit "room/room";
reset(arg){
        if(!arg){
        set_light(1);
        short_desc="A Corridor";
        long_desc="Yup, you're still in the drab hallway, better get used to it, cause\n"+
                "that's all there is up here on the second level.\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor2/room3","west",
                "players/rumplemintz/room/bane/castle/floor2/room5","southeast",
        });
        }
}
