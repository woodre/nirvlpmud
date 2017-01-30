inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main Street";
    no_castle_flag = 0;
    long_desc = 
        "You are on the main street of ReesePort.  To the east you can see the\n"
+"beginning of a very dark trail and to the northeast you can see the town's\n"
+"inn.\n";
    dest_dir = 
        ({
         "players/grimm/town/mainstreet_8", "north",
         "players/grimm/town/road_1", "east",
        });
}

