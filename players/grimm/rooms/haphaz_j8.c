inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Windy Room";
    no_castle_flag = 0;
    long_desc = 
        "You are in a very chilly room.  To the west you can see nothing but open\n"
        + "space.  There is a very strong wind that also comes from that direction.\n"
        + "You can also see that the eastern room's east side ends abruptly.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_j7", "north",
         "players/grimm/rooms/haphaz_k8", "east",
         "players/grimm/rooms/haphaz_j9", "south",
        });
}

