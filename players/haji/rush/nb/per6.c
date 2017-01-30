inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc= "Perimeter of the naval base";
    long_desc = 
        "The is the perimeter of the naval base.\n" +
        "You see the exit to the north and the base to the south.\n";
    dest_dir = ({"players/haji/rush/nb/ent", "north",
                 "players/haji/rush/nb/per7", "east",
                 "players/haji/rush/nb/per5" ,"west",
		 "players/haji/rush/nb/base1", "south"});
}

