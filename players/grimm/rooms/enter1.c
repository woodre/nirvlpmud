inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Caverns";
    no_castle_flag = 0;
    long_desc = 
        "You have entered some caverns that have been dug into the ground.  Coming from\n"+
        "all directions, you can see fog pouring into the room.  This area feels strange;\n"+
        "as though each step will take you miles away.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_a6", "southwest",
         "players/grimm/newbie/rooms/entrance", "up",
         "players/grimm/rooms/haphaz_c5", "east",
        });
}

query_light() {
    return 1;
}

