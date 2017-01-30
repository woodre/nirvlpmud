inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Dwarf Lord's wilderness";
        long_desc = "     You are out in the wilderness of Dwarf territory.\n";

        dest_dir = ({

                "players/rumplemintz/room/dlords/room7", "south",
                "players/rumplemintz/room/dlords/room17", "north",
                });

        }
}
