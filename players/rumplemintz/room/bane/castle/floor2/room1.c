inherit "room/room";
reset(arg){
        if(!arg){
        set_light(1);
        short_desc="Nowhere";
        long_desc="  As you assault the mighty stairway, (notice the tiredness of\n"+
                "the coder, and his lack of imagination), you find, that this is just\n"+
                "another corridor, plain as a baby's butt.\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor1/room34","down",
                "players/rumplemintz/room/bane/castle/floor2/room2","northeast",
        });
        }
}
