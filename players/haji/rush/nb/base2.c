inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
     short_desc = "Road on a naval base";
    long_desc = 
        "The is the main road on the naval base.\n" +
        "The pub is to the west and the commisary is to east.\n";
    dest_dir = ({"players/haji/rush/nb/base1", "north",
                 "players/haji/rush/nb/pub", "west",
                 "players/haji/rush/nb/comm", "east",
		 "players/haji/rush/nb/base2", "south"});
}

