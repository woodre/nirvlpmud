inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Semi-Foggy Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a well carved room.  Although the fog is still in the\n"
        + "air you can notice that it has gotten easier to see and breath.\n"
        + "You can hear a rucus from all around that sounds like people arguing.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_i6", "east",
         "players/grimm/rooms/haphaz_h7", "south",
        });
}

