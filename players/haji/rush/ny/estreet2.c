inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Downtown New York";
    long_desc = 
       "You are in downtown New York and see many buildings in all directions.\n" +
       "Off in the distance to the north you see city hall.\n" +
       "To the south you see central park in the distance.\n" +
       "To the west in Grand Central station and east\n" +
       "is the local pub.\n";
    dest_dir = ({"players/haji/rush/ny/estreet3", "north",
		 "players/haji/rush/ny/gcsta", "west",
                 "players/haji/rush/ny/pub", "east",
		 "players/haji/rush/ny/estreet1", "south"});
}

