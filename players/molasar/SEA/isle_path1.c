

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A small slope";
    no_castle_flag = 0;
    long_desc = 
        "You have reached a small slope.  A path leads down to the western shore\n"
        + "of the isle while the path continues to the northeast.\n";
    dest_dir = 
        ({
        "players/molasar/SEA/isle_path2", "northeast",
        "players/molasar/SEA/isle_beach", "down",
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

