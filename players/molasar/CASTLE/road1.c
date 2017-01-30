

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A cobblestone road";
    no_castle_flag = 0;
    long_desc = 
        "This is the beginning of a cobblestone road.  The main entrance\n"
        + "of the castle lies to the north while the road comtinues south.\n";
    dest_dir = 
        ({
        "players/molasar/CASTLE/entrance", "north",
        "players/molasar/CASTLE/road2", "south",
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

