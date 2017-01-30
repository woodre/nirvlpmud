inherit "room/room";

reset(arg) {
    if (arg) return;

   set_light(1);
    short_desc = "A Shiny Walled Room";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a small room.  Amazingly you can see no trace of the fog \n"
        + "from the other rooms.  The walls are very slick and highly polished.\n"
        + "To the south you can see a glimmering light.  Something\n"
        + "tells you that you really shouldn't go down there.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_c8", "east",
         "players/grimm/rooms/haphaz_b9", "south",
        });
}

query_light() {
    return 1;
}

