inherit "room/room";
int i;
reset(arg) {
         if(!present("fighter"))
          move_object(clone_object("players/rumplemintz/mon/dwarf/dfighter.talk"), this_object());
        if(!arg) {
                set_light(1);
         short_desc = "Dwarven Kingdom entrance";
        long_desc = "     This is the entrance to the Kingdom of the Dwarf Lords.  There\n"+
                "two Dwarven Fighters guarding the gates, you need not kill them, but it\n"+
                "might prove fruitful to do so.  Then again it might not.\n";

        dest_dir = ({
		"players/rumplemintz/room/dlanding", "south",
                "players/rumplemintz/room/dlords/room2", "east",
                "players/rumplemintz/room/dlords/room4", "west",
                "players/rumplemintz/room/dlords/room8", "north",
                "players/rumplemintz/room/dlords/room9", "northeast",
                "players/rumplemintz/room/dlords/room7", "northwest",
                });

        }
}
