

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "A small room";
    no_castle_flag = 0;
    long_desc = 
        "This appears to be someones sleeping area.  There are many footprints\n"
        + "in the area and old discarded items of no interest.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/tunnel6", "down",
        "players/molasar/UNDER/tunnel8", "west",
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

