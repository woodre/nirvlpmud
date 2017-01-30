

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A north south road";
    no_castle_flag = 0;
    long_desc = 
        "The road continues to the north.  Up ahead you see a bridge crossing a dirty\n"
        + "brown river.\n";
    dest_dir = 
        ({
        "/players/blackadder/w1/road2", "south",
        "/players/blackadder/w1/bridge", "north",
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

