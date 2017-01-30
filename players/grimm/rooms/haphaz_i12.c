inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Bottom of the Crater";
    no_castle_flag = 0;
    long_desc = 
"You are standing at the bottom of a very large crater.  You may be able\n"
+"to climb up elsewhere but that is impossible here.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_h11", "northwest",
         "players/grimm/rooms/haphaz_i11", "north",
         "players/grimm/rooms/haphaz_j11", "northeast",
         "players/grimm/rooms/haphaz_j12", "east",
         "players/grimm/rooms/haphaz_j13", "southeast",
         "players/grimm/rooms/haphaz_i13", "south",
         "players/grimm/rooms/haphaz_h13", "southwest",
         "players/grimm/rooms/haphaz_h12", "west",
        });
}

