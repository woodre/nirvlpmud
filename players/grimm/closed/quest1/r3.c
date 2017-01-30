inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Room 3";
    no_castle_flag = 0;
    long_desc = 
        "Room 3.\n"
        + "This is one of the catacombs under the city. There is a mist in the\n"
        + "ajoining hallways that makes you feel like you are going in circles.\n";
    dest_dir = 
        ({
         "players/grimm/closed/quest1/r1", "north",
         "players/grimm/closed/quest1/r1", "east",
         "players/grimm/closed/quest1/r2", "south",
         "players/grimm/closed/quest1/r4", "west",
        });
}

realm() { return "NT"; }
