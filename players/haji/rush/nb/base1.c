inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
     short_desc = "Road on a naval base";
    long_desc = 
        "The is the main road on the naval base.\n" +
        "The welfare is to the west and the shop is to east.\n";
    dest_dir = ({"players/haji/rush/nb/per6", "north",
                 "players/haji/rush/nb/welfoff", "west",
                 "players/haji/rush/nb/shop", "east",
		 "players/haji/rush/nb/base2", "south"});
}

