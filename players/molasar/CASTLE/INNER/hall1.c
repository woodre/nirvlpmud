

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A hallway in the castle";
    no_castle_flag = 0;
    long_desc = 
        "This is the center of a hallway which runs north and south.  A large\n"
        + "lobby lies to the west.\n";
    dest_dir = 
        ({
        "players/molasar/CASTLE/INNER/entry", "east",
        "players/molasar/CASTLE/INNER/lobby", "west",
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

