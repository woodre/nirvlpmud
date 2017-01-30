

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Island shore on main road";
    no_castle_flag = 0;
    long_desc = 
        "You are on the shore of the island.  You can see the hazy crater of the\n"
        + "volcano far to the north.  Immediately to the north is a marshland so thick\n"
        + "you can't see into it at all.  \n";
    dest_dir = 
        ({
        "/players/deathmonger/castle_shore", "portal",
        "/players/deathmonger/main1", "north",
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

