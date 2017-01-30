

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Main road";
    no_castle_flag = 0;
    long_desc = 
        "The swamp grows thicker.  The vines and Spanish moss on the trees seem to be\n"
        + "reaching down to you as if to entangle you.  \n";
    dest_dir = 
        ({
        "/players/deathmonger/main1", "south",
        "/players/deathmonger/main3", "north",
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

