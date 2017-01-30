

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Edge of a forest";
    no_castle_flag = 0;
    long_desc = 
        "You have come upon the edge of a great forest.  Trees of many varieties\n"
        + "begin to make themselves apparent.  The forest becomes more\n"
        + "dense to the east.\n";
    dest_dir = 
        ({
        "players/molasar/PLAINS/plain8", "west",
        "players/molasar/FOREST/forest1", "east",
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

