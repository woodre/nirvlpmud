inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Lord Bane's wilderness";
        long_desc = "     You are out in the wilderness of Bane's territory.\n"+
                "You finally notice what looks like a castle in the southeast.\n";

        dest_dir = ({

                "players/rumplemintz/room/bane/castle/outside","southeast",
		"players/rumplemintz/room/bane/room14", "east",
                });

        }
}
