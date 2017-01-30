inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Underground Caverns";
    no_castle_flag = 0;
    long_desc = 
        "You are in an underground cavern.  The floor is very damp, as are the walls.\n"
        + "Off in the distance you can hear running water.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_i5", "northwest",
         "players/grimm/rooms/haphaz_k5", "northeast",
         "players/grimm/rooms/haphaz_k7", "southeast",
         "players/grimm/rooms/haphaz_i7", "southwest",
        });
}

