inherit "room/room";

reset(arg) {
    if (arg) return;

    short_desc = "Foggy Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a foggy room.  There is a mist here that highly resembles\n"
        + "a thick cloud of dust.  Breathing is difficult, but possible.  The walls\n"
        + "are rough and seem to have been made in a hurry.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_d10", "northeast",
         "players/grimm/rooms/haphaz_b10", "northwest",
         "players/grimm/rooms/haphaz_c12", "south",
         "players/grimm/rooms/haphaz_d12", "southeast",
        });
}

query_light() {
    return -1;
}

