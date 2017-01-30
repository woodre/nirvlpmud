

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "A tunnel underneath the mountain";
    no_castle_flag = 0;
    long_desc = 
        "A tunnel underneath the mountain.  You have gotten used to stale air\n"
        + "so that you do not notice it anymore.  The tunnel continues to the\n"
        + "east and west.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/tunnel3", "east",
        "players/molasar/UNDER/tunnel5", "west",
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

