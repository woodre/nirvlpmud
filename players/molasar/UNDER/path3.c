

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Outer base of the mountain";
    no_castle_flag = 0;
    long_desc = 
        "You are at the outer base of the mountain.  Walking is very difficult\n"
        + "due to fallen rock and debris, but you manage to make it\n"
        + "without twisting anything.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/foot", "north",
        "players/molasar/UNDER/path2", "south",
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

