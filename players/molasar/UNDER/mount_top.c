

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A mountain top";
    no_castle_flag = 0;
    long_desc = 
        "You have reached the top of the mountain.  You position gives you\n"
        + "a grand view of the surrounding areas, stretching for miles in every\n"
        + "direction.  A small winding path leads north.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/trail1", "north",
        "players/molasar/UNDER/climb2", "down",
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

