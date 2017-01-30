

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Middle of the tower";
    no_castle_flag = 0;
    long_desc = 
        "This is the middle of the tower.  It is evidently a resting place for the\n"
        + "guards on duty.  A table and two chairs are next to one wall and a\n"
        + "small cot lies in the corner.  The stairs continue up.\n";
    dest_dir = 
        ({
        "players/molasar/CASTLE/tower2_3", "up",
        "players/molasar/CASTLE/tower2_1", "down",
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

