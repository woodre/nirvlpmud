inherit "room/room";

reset(arg) {
    if (arg) return;

    short_desc = "Littered Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a very dirty room.  You can see trash and litter all over\n"
        + "the floor sloping up to the walls.  To the east you can hear some noises.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_c6", "east",
         "players/grimm/rooms/haphaz_a6", "west",
        });
}

query_light() {
    return -1;
}

