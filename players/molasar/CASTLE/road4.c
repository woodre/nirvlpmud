

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A small road";
    no_castle_flag = 0;
    long_desc = 
        "This is a small road between the garden to the south and the northeastern\n"
        + "tower of the castle.\n";
    dest_dir = 
        ({
        "players/molasar/CASTLE/tower2_1", "north",
        "players/molasar/CASTLE/garden2", "south",
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

