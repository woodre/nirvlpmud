

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "A long, dark tunnel";
    no_castle_flag = 0;
    long_desc = 
        "This is a long dark tunnel.\n";
    dest_dir = 
        ({
        "/players/deathmonger/UNDERDARK/tunnel5a", "west",
        "/players/deathmonger/UNDERDARK/tunnel3", "north",
        "/players/deathmonger/UNDERDARK/tunnel5b", "east",
        });
}

query_light() {
    return 0;
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

