

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "A crawlspace";
    no_castle_flag = 0;
    long_desc = 
        "The tunnel has gotten so small here that you must get on your belly\n"
        + "and crawl to get through.  The rocks and debris dig painfully into your body.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/tunnel7", "east",
        "players/molasar/UNDER/tunnel9", "south",
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

