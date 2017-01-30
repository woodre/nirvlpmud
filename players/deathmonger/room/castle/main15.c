

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "More mountains";
    no_castle_flag = 0;
    long_desc = 
        "You climb the mountains.  A Darkenbeast flies overhead, indicating the\n"
        + "presence of an evil wizard nearby.  The way is steep and treacherous, and\n"
        + "you frequently find yourself nearly falling.  A billygoat says,\n"
        + "BAAAAAAAAAHH!.\n";
    dest_dir = 
        ({
        "/players/deathmonger/main14", "down",
        "/players/deathmonger/main16", "up",
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

