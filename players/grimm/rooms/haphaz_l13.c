inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Cannon Room Entrance";
    no_castle_flag = 0;
    long_desc = 
        "You are in a room that opens up to what you can tell to be a rather large\n"
        + "cannon.  To the east you can smell the recent remains of burned gunpowder.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_k13", "west",
         "players/grimm/rooms/cannon1", "east",
        });
}

