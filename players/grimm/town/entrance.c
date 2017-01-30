inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Entrance to ReesePort";
    no_castle_flag = 0;
    long_desc = 
        "This is the main road of the town of ReesePort.  This town is rather small\n"
        + "as it is just a branch of a much larger city (Reese).  Unfortunately, the\n"
        + "docks have been torn down by severe weather and poor maintenance.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_d13", "north",
         "players/grimm/town/mainstreet_3", "south",
        });
}

