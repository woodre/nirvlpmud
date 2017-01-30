inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Entrance to the Catacombs";
    no_castle_flag = 0;
    long_desc = 
        "Room 1.\n"
        + "This is the entrance of the catacombs under the city. There is a mist in the\n"
        + "ajoining hallways that makes you feel like you are going in circles.\n";
    dest_dir = 
        ({
         "players/grimm/closed/quest1/r2", "east",
         "players/grimm/rooms/haphaz_c4", "up",
        });
}

realm() { return "NT"; }
