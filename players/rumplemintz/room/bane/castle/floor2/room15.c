inherit "room/room";
reset(arg){
        if(!arg){
        set_light(0);
        short_desc="A hidden room";
        long_desc="The stairway to third floor, you found it, unbelievable.  Well\n"+
                "since you have discovered it, maybe you should take a look up there.\n"+
                "but then again, maybe you shouldn't, only time will tell...\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/floor2/room14","south",
                "players/rumplemintz/room/bane/castle/floor3/room1","up",
        });
        }
}
