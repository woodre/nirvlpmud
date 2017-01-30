

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Up the mountain";
    no_castle_flag = 0;
    long_desc = 
        "Your ears begin to pop at the change in pressure.  Looking up you begin\n"
        + "to wonder if you really want to continue.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/foot", "down",
        "players/molasar/UNDER/climb2", "up",
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

