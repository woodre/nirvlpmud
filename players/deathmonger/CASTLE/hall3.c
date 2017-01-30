

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "hall3";
    no_castle_flag = 0;
    long_desc = 
        "End of hall.  You can see the sea to the north.\n";
    dest_dir = 
        ({
        "/players/deathmonger/hall2", "south",
        "/players/deathmonger/castle_shore", "north",
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

