

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main road";
    no_castle_flag = 0;
    long_desc = 
        "You are really sweating from the humidity now and you'll be lucky if you\n"
        + "don't get heatstroke from the heat.  The parrots' screaching is really \n"
        + "beginning to annoy you and you wish you were out of the jungle.  How does\n"
        + "Tarzan survive here?\n";
    dest_dir = 
        ({
        "/players/deathmonger/main5", "south",
        "/players/deathmonger/main7", "north",
        "/players/deathmonger/CASTLE/tarzan_room", "east",
        "/players/deathmonger/CASTLE/george_room", "west",
        });
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
/*
room_is_modified() {
    return 1;
}
*/

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

