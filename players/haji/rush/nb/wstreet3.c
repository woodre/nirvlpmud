inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Downtown New York";
    long_desc = 
       "You are in downtown New York and see many buildings in all directions.\n" +
       "Off in the distance to the north you see the NBC building.\n" +
       "To the south you see the EIB building, home of the great\n" +
       "Rush Limbaugh.  To the east is Grand Central station.\n" +
       "Finally, to the west is the local shop.\n";
    dest_dir = ({"players/haji/rush/ny/wstreet4", "north",
		 "players/haji/rush/ny/gcsta", "east",
                 "players/haji/rush/ny/shop", "west",
		 "players/haji/rush/ny/wstreet2", "south"});
}

