

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "hall";
    no_castle_flag = 0;
    long_desc = 
        "You are near the north end of the great hall.\n";
    dest_dir = 
        ({
        "/players/blackadder/hall5", "north",
        "/players/blackadder/hall3", "south",
        "/players/blackadder/shop", "west",
        "/players/blackadder/morgue", "east",
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

