inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main Street";
    no_castle_flag = 0;
    long_desc = 
"You are on the main street of ReesePort. South of you is the town pub.\n"
        + "To the southwest you can see the town's general store.\n";
    dest_dir = 
        ({
         "players/grimm/town/entrance", "north",
         "players/grimm/town/mainstreet_4", "east",
         "players/grimm/town/pub", "south",
         "players/grimm/town/mainstreet_2", "west",
        });
}

