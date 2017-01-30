inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main Street";
    no_castle_flag = 0;
    long_desc = 
        "You are on the main street of ReesePort.  To the south, you can see the \nbeginning of a dark trail.\n";
    dest_dir = 
        ({
         "players/grimm/town/mainstreet_6", "north",
         "players/grimm/town/mainstreet_10", "south",
        });
}

