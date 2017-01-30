inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Top of a Chasm";
    no_castle_flag = 0;
    long_desc = 
        "You are on the edge of a large chasm.  You cannot see the bottom or the\n"
        + "other side.  The wind is rather stiff and you have a hard time keeping\n"
        + "your balance.  To the southeast you can faintly smell the remains of \n"
        + "recently burned gunpowder.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_l11", "north",
         "players/grimm/rooms/cannon1", "southeast",
        });
}

