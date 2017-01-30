inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Lord Bane's wilderness";
        long_desc = "     You are out in the wilderness of Bane's territory.\n";

        dest_dir = ({

                "players/rumplemintz/room/bane/room9", "southwest",
		"players/rumplemintz/room/bane/room10", "west",
                });

        }
}
