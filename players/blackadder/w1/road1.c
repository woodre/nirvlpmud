

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A road running North";
    no_castle_flag = 0;
    long_desc = 
        "This is a road running north/south.  From the west you hear the sound of\n"
        + "rushing water.\n";
    dest_dir = 
        ({
        "/players/blackadder/w1/circle", "south",
        "/players/blackadder/w1/road2", "north",
        "/players/blackadder/w1/river1", "west",
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

