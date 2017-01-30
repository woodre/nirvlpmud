

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "hall";
    no_castle_flag = 0;
    long_desc = 
        "This is the main hallway.  It runs north-south from one end of the \n"
        + "castle to the other.  A red carpet covers the floor and extends\n"
        + "the length of the hall.\n";
    dest_dir = 
        ({
        "/players/blackadder/entrance", "south",
        "/players/blackadder/hall2", "north",
        "/players/blackadder/bathroom", "west",
        "/players/blackadder/bedroom", "east",
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

