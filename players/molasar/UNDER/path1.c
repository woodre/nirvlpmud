inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A dirt path";
    no_castle_flag = 0;
    long_desc = 
        "You are walking along a dusty path.  Huge rock walls lie on either\n"
        + "side of you.  Off into the distant north you see a large mountain.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/path2", "north",
        "room/sunalley2", "south",
        });
}

query_light() {
    return 1;
}
