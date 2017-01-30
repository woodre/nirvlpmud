inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Damp Room";
    no_castle_flag = 0;
    long_desc = 
        "The fog here has lifted quite a bit.  The room is quite damp and you can\n"
        + "see to the east that the floor is several inches under water.  There is a\n"
        + "light source of unknown origin on the wall (possibly a form of algae).\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_h9", "east",
         "players/grimm/rooms/haphaz_f8", "northwest",
        });
}

