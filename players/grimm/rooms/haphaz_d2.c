inherit "room/room";

reset(arg) {
    if (arg) return;

    short_desc = "Underground Caverns";
    no_castle_flag = 0;
    long_desc = 
        "The air here is much clearer.  Although it is easier to see there is still\n"
        + "a faint cloud of dust in the air.  The walls are rough and seems to have\n"
        + "been made in a hurry.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_e2", "east",
         "players/grimm/rooms/haphaz_d3", "south",
        });
}

query_light() {
    return -1;
}

