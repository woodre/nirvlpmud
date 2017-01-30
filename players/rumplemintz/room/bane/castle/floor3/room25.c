inherit "room/room";
reset(arg){
        if(!arg){
        set_light(1);
        short_desc="Nowhere";
        long_desc="Congratulations, you've found the hidden stairway to the top floor.\n"+
                "Good luck on the rest of your journey...\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor3/room24","east",
                "players/rumplemintz/room/bane/castle/floor4/room1","up",
        });
        }
}
