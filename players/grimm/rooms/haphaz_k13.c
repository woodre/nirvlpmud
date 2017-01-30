inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Misty Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a misty room.  To the east you can smell what seems to be\n"
        + "the remains of recently burned gunpowder.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_k12", "north",
         "players/grimm/rooms/haphaz_j13", "west",
         "players/grimm/rooms/haphaz_l13", "east",
        });
}
