inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Lord Bane's wilderness";
        long_desc = "     You are out in the wilderness of Bane's territory.\n";

        dest_dir = ({

                "players/rumplemintz/room/bane/room1", "south",
                "players/rumplemintz/room/bane/room4", "north",
                "players/rumplemintz/room/bane/room6", "east",
                "players/rumplemintz/room/bane/room5", "southeast",
                "players/rumplemintz/room/bane/room7", "northeast",
                });

        }
}
