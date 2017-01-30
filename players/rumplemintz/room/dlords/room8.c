inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Entrance to Dwarf Lord's castle";
        long_desc = "     This is a path to the Dwarf Lord's castle.  You can see it from\n"+
                "here, and it doesn't look very impressive.  Although it does look mean.\n";

        dest_dir = ({

                "players/rumplemintz/room/dlords/room1", "south",
                "players/rumplemintz/room/dlords/castle/outside", "north",
                });

        }
}
