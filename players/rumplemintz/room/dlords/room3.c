inherit "room/room";
reset(arg) {
        if(!present("fighter")) {
           move_object(clone_object("players/rumplemintz/mon/dwarf/dfighter"), this_object());
   }
        if(!arg) {
                set_light(1);
        short_desc = "Dwarf Lord's wilderness";
        long_desc = "     You are out in the wilderness of Dwarf territory.\n";

        dest_dir = ({

                "players/rumplemintz/room/dlords/room2", "west",
                "players/rumplemintz/room/dlords/room10", "north",
                });

        }
}
