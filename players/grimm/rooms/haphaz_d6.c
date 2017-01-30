inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Slimy Room";
    no_castle_flag = 0;
    long_desc = 
"This is a rather disgusting room.  The walls are covered in slime and the\n"
+"floor is slick from some unknown substance.  To the west you can hear\n"
+"something moving around.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_e6", "east",
         "players/grimm/rooms/haphaz_c7", "southwest",
        });
}

query_light() {
    return 1;
}

