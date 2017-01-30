

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Edge of a cliff";
    no_castle_flag = 0;
    long_desc = 
        "You have reached the edge of a cliff.  Looking out you see a large sea\n"
        + "and a small isle to the west.  A path leads down to the shore.\n";
    dest_dir = 
        ({
        "players/molasar/PLAINS/plain24", "north",
        "players/molasar/PLAINS/plain4", "east",
        "players/molasar/SEA/cliff1", "down",
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

