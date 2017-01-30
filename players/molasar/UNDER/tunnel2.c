

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A tunnel underneath the mountain";
    no_castle_flag = 0;
    long_desc = 
        "You have hardly gone into the tunnel and you start to feel cold.\n"
        + "There air is stale and makes breathing difficult.  The lighting\n"
        + "is getting very dim and you can barely see your way to continue.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/tunnel1", "north",
        "players/molasar/UNDER/tunnel3", "south",
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

