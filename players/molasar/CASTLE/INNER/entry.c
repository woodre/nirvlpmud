

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Entry of the castle";
    no_castle_flag = 0;
    long_desc = 
        "This is the entry of the castle.  A giant red carpet lies on the white\n"
        + "marble floor.  Emblazoned on the carpet is the symbol of a giant dragon\n"
        + "clutching a sword.  A hall lies to the west and the outer compound to\n"
        + "the east.\n";
    dest_dir = 
        ({
        "players/molasar/CASTLE/cpath2", "east",
        "players/molasar/CASTLE/INNER/hall1", "west",
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

