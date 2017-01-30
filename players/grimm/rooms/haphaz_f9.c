inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Misty Room";
    no_castle_flag = 0;
    long_desc = 
        "The heavy fog has lifted somewhat here.  Breathing is quite a bit easier.\n"
        + "To the southeast you can feel a small breeze blowing and there seems to\n"
        + "be a light source eminating in that direction also.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_f10", "south",
         "players/grimm/rooms/haphaz_g10", "southeast",
        });
}

query_light() {
    return 0;
}

