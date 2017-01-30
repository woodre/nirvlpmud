inherit "room/room";
reset(arg){
        if(!arg){
        set_light(1);
        short_desc="A Corridor";
        long_desc="Yup, you're still in the drab hallway, better get used to it, cause\n"+
                "that's all there is up here on the third level too.\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor3/room9","southeast",
                "players/rumplemintz/room/bane/castle/floor3/room11","northwest",
        });
        }
}
