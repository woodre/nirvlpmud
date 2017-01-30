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
         "players/grimm/rooms/haphaz_j3", "north",
         "players/grimm/rooms/haphaz_k4", "east",
        });
}

