inherit "room/room";
reset(arg) {
        if(!present("warrior")) {
          move_object(clone_object("players/rumplemintz/mon/bane/skwarr2"), this_object());
    }
        if(!arg) {
                set_light(1);
        short_desc = "Lord Bane's wilderness";
        long_desc = "     You are out in the wilderness of Bane's territory.\n";

        dest_dir = ({

                "players/rumplemintz/room/bane/room10", "northeast",
                "players/rumplemintz/room/bane/room9", "east",
                "players/rumplemintz/room/bane/room8", "southeast",
                "players/rumplemintz/room/bane/room3", "west",
                });

        }
}
