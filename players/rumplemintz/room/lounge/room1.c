inherit "room/room";

reset(arg) {
        if(!arg) {
                set_light(1);
         short_desc = "A dark and eerie, seldom traveled path.";
         long_desc = "     As you step onto the path, it is very noticable that it hasn't\n"+
                "been traveled in a long, long time.  You think twice about continuing\n"+
                "onward, and your heart starts to beat faster.  Off in the distance you\n"+
                "hear laughing?  Could this be?  You must be dreaming, better go back.\n";

        dest_dir = ({

                "players/rumplemintz/room/central", "northeast",
		"players/rumplemintz/room/lounge/room2", "southwest",
                });

        }
}
