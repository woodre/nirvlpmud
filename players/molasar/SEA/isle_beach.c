

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Western shore of the isle";
    no_castle_flag = 0;
    long_desc = 
        "You have reached the western shore of the isle.  A small rocky trail\n"
        + "leads up a small slope.\n";
    dest_dir = 
        ({
        "players/molasar/SEA/isle_path1", "up",
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

